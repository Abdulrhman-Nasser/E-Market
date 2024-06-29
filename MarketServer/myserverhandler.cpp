
#include "myserverhandler.h"
MyServerHandler::MyServerHandler(qint32 ID, QObject *parent)
    :id(ID), QThread{parent}
{
    LoginData.setPath(QDir::currentPath()+"/debug/LoginDB.json");
    ProductsDB.setPath(QDir::currentPath()+"/debug/ProductsDB.json");
}

void MyServerHandler::sendMessage(QString str,QString Type)
{
    if(socket->isOpen())
    {
        QJsonObject jsonObject;
        jsonObject["file_type"]=Type;
        jsonObject["file_size"]=str.toUtf8().size();
        jsonObject["file_data"]=str;
        QByteArray byteArray= QJsonDocument(jsonObject).toJson(QJsonDocument::Compact);
        QString header = QString("JsonSize:%1/").arg(byteArray.size());
        byteArray.prepend(header.toUtf8());
        qDebug()<<byteArray;
        socket->write(byteArray);
    }
}

void MyServerHandler::Operations(QString str,QString Type)
{

    if(Type == "Login")
    {
        QStringList list = str.split('\n');
        QString username = list[0];
        QString pass = list[1];
        Login(username,pass.toInt());
    }
    else if(Type == "SignOut")
    {
        QJsonArray jsonarr=LoginData.readFile();
        for(int i=0 ; i<jsonarr.size();i++)
        {
            QJsonObject jsonobj= jsonarr[i].toObject();
            QString user = jsonobj["UserName"].toString();
            qint32 password = jsonobj["Password"].toInt();
            if(user == name && password == pass)
            {
                jsonobj["Available"] = true;
                jsonarr[i]=jsonobj;
                LoginData.writeFile(jsonarr);
                break;
            }
        }
    }
    else if(Type == "GetDataBase")
    {
        QJsonArray jsonarr = ProductsDB.readFile();
        QJsonDocument doc;
        doc.setArray(jsonarr);
        QString data(doc.toJson());
        sendMessage(data,"Data");
    }
    else if(Type ==  "CheckOut")
    {
        invoceProducts.clear();
        QJsonArray jsonarr=LoginData.readFile();
        QString city;
        QString gov;
        QString dis;
        QString building;
        QString apt;
        QString email;
        qint32 number;
        for(int i=0 ; i<jsonarr.size();i++)
        {
            QJsonObject jsonobj= jsonarr[i].toObject();
            QString user = jsonobj["UserName"].toString();
            qint32 password = jsonobj["Password"].toInt();
            QString Authority = jsonobj["Auth"].toString();
            if(user == name && this->pass == password)
            {
                city = jsonobj["City"].toString();
                gov = jsonobj["Governorate"].toString();
                dis = jsonobj["District"].toString();
                building = jsonobj["Building no."].toString();
                apt = jsonobj["Apt no."].toString();
                email = jsonobj["Email"].toString();
                number = jsonobj["Phone Number"].toInt();
                QString data=city+"\n"+gov+"\n"+dis+"\n"+building+"\n"+apt+"\n"+email+"\n"+QString::number(number);
                qDebug()<<data;
                if(data=="\n\n\n\n\n\n0")
                {
                    sendMessage("No Address Found","Error");
                    return;
                }
            }

        }

        QJsonArray jsonarrproducts = ProductsDB.readFile();
        QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
        QJsonArray jsonarrcheckout = doc.array();
        // Iterate through each item in the checkout array
        for (int i =0 ; i<jsonarrcheckout.size() ; i++) {
            QJsonObject checkoutObject= jsonarrcheckout[i].toObject();
            qDebug()<<"Before => "<<checkoutObject["id"].toInt();
            qint32 checkoutId = checkoutObject["id"].toInt();
            qint32 checkoutQuantity = checkoutObject["quantity"].toInt();

            // Find the corresponding item in the product array by id
            for (int i = 0; i < jsonarrproducts.size(); ++i) {
                QJsonObject productObject = jsonarrproducts[i].toObject();
                if (productObject["id"] == checkoutId) {
                    // Subtract the quantity
                    int productQuantity = productObject["quantity"].toInt();
                    qDebug()<<"product quantity => "<<productQuantity;
                    productObject["quantity"] = productQuantity - checkoutQuantity;
                    // Update the product array with the modified object
                    jsonarrproducts[i] = productObject;
                    invoceProducts.append(Product(productObject["name"].toString(),checkoutQuantity,productObject["price"].toDouble()));
                    break;
                }
            }
        }
        ProductsDB.writeFile(jsonarrproducts);
        QString msg=invoice.editHtmlFile("template.html",name,city+", "+gov,dis,building,apt,email,number,invoceProducts);
        QStringList command;
        command<<"wkhtmltopdf --enable-local-file-access "+QDir::currentPath()+"/invoice.html "+QDir::currentPath()+"/tst.pdf";
        invoice.runCommand(command);
        sendMessage(msg,"SuccessCheckout");

    }
    //  Signup
    else if(Type ==  "Signup")
    {
        QStringList list = str.split('\n');
        QString username = list[0];
        QString pass = list[1];
        QJsonArray jsonarr=LoginData.readFile();
        for(int i=0 ; i<jsonarr.size();i++)
        {
            QJsonObject jsonobj= jsonarr[i].toObject();
            QString user = jsonobj["UserName"].toString();
            qint32 password = jsonobj["Password"].toInt();
            QString Authority = jsonobj["Auth"].toString();
            if(user == username && pass.toInt() == password)
            {
                sendMessage("User already exists!","Error");
                return;
            }
        }
        QJsonObject jsonObject;
        jsonObject["Auth"] = "User";
        jsonObject["Password"] = pass.toInt();
        jsonObject["UserName"] = username;
        jsonarr.append(jsonObject);
        LoginData.writeFile(jsonarr);
        name = username;
        this->pass=pass.toInt();
        sendMessage("User","SuccessLogin");
    }
    //  Address save
    else if(Type ==  "Save_Address")
    {
        QStringList list = str.split('\n');
        QString city = list[0];
        QString gov=list[1];
        QString dis=list[2];
        QString building=list[3];
        QString apt = list[4];
        QString email = list[5];
        qint32 number = list[6].toInt();
        qDebug()<<city<<gov<<dis<<building<<apt;
        QJsonArray jsonarr=LoginData.readFile();
        for(int i=0 ; i<jsonarr.size();i++)
        {
            QJsonObject jsonobj= jsonarr[i].toObject();
            QString user = jsonobj["UserName"].toString();
            qint32 password = jsonobj["Password"].toInt();
            QString Authority = jsonobj["Auth"].toString();
            if(user == name && pass == password)
            {
                jsonobj["City"]=city;
                jsonobj["Governorate"]=gov;
                jsonobj["District"]=dis;
                jsonobj["Building no."]=building;
                jsonobj["Apt no."]=apt;
                jsonobj["Email"]=email;
                jsonobj["Phone Number"]=number;
                jsonarr[i]=jsonobj;
                break;
            }
        }
        LoginData.writeFile(jsonarr);
    }
    else if(Type ==  "Get_Address")
    {
        QJsonArray jsonarr=LoginData.readFile();
        for(int i=0 ; i<jsonarr.size();i++)
        {
            QJsonObject jsonobj= jsonarr[i].toObject();
            QString user = jsonobj["UserName"].toString();
            qint32 password = jsonobj["Password"].toInt();
            QString Authority = jsonobj["Auth"].toString();
            QString city = jsonobj["City"].toString();
            QString gov = jsonobj["Governorate"].toString();
            QString dis = jsonobj["District"].toString();
            QString building = jsonobj["Building no."].toString();
            QString apt = jsonobj["Apt no."].toString();
            QString email = jsonobj["Email"].toString();
            qint32 number = jsonobj["Phone Number"].toInt();
            if(user == name && this->pass == password)
            {
                QString data=city+"\n"+gov+"\n"+dis+"\n"+building+"\n"+apt+"\n"+email+"\n"+QString::number(number);
                sendMessage(data,"Address");
            }

        }
    }
    else if(Type ==  "Get_Name")
    {
        sendMessage(name,"Name");
    }
    else if(Type == "New_Product")
    {
        QJsonArray jsonarrproducts = ProductsDB.readFile();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
        QJsonObject newjsonobj = jsonDoc.object();
        for(int i = 0 ; i<jsonarrproducts.size(); i++)
        {
            QJsonObject jsonobj = jsonarrproducts[i].toObject();
            if(jsonobj["id"] == newjsonobj["id"])
            {
                sendMessage("ID already exists!","Error");
                return;
            }

        }

        jsonarrproducts.append(newjsonobj);
        ProductsDB.writeFile(jsonarrproducts);
    }
    else if(Type == "Delete_Product")
    {
        QJsonArray jsonarrproducts = ProductsDB.readFile();
        QJsonArray newJsonArrProducts;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
        QJsonObject jsonobj = jsonDoc.object();
        for(int i = 0; i<jsonarrproducts.size() ; i++ )
        {
            QJsonObject temp = jsonarrproducts[i].toObject();
            if(( (temp["id"]!= jsonobj["id"]) && (temp["name"] != jsonobj["name"]) ) )
            {
                newJsonArrProducts.append(temp);
            }
        }
        ProductsDB.writeFile(newJsonArrProducts);
    }
    else
    {
        qDebug()<<"Type -> "<<Type<<" is unknown!..";
    }
}

void MyServerHandler::Login(QString username, qint32 pass)
{
    qDebug()<<"Attempting to login with user name -> "<<username<<" and password -> "<<pass;
    QJsonArray jsonarr=LoginData.readFile();
    for(int i=0 ; i<jsonarr.size();i++)
    {
        QJsonObject jsonobj= jsonarr[i].toObject();
        QString user = jsonobj["UserName"].toString();
        qint32 password = jsonobj["Password"].toInt();
        QString Authority = jsonobj["Auth"].toString();
        bool available = jsonobj["Available"].toBool();
        if(user == username && pass == password)
        {
            if(available)
            {
                jsonobj["Available"]=false;
                jsonarr[i]=jsonobj;
                LoginData.writeFile(jsonarr);
                qDebug()<<"Login success with authority -> "<<Authority;
                name = username;
                this->pass=pass;
                sendMessage(Authority,"SuccessLogin");
                return;
            }
            else
            {
                sendMessage("User in use!","Error");
                return;
            }
        }

    }
    qDebug()<<"Login failed!";
    sendMessage("User Not Found!","Error");
}

void MyServerHandler::onReadyRead()
{
    QByteArray byteArray=socket->readAll();
    QString str = QString(byteArray);
    qint32 jsonSize=str.split("/")[0].split(":")[1].toInt();
    QString data = str.right(jsonSize);
    QJsonDocument jsonDoc=QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    QString Type = jsonObject["file_type"].toString();
    qint32 dataSize=jsonObject["file_size"].toInt();
    QString realData = jsonObject["file_data"].toString();
    if(dataSize == realData.size())
    {
        qDebug()<<"Received data from client "<<id<<" =>" <<realData;
        Operations(realData,Type);
    }
    else
    {
        qDebug()<<"Something wrong with the data!";
    }

}

void MyServerHandler::onDisconnected()
{
    if(socket->isOpen())
    {
        socket->close();
        qDebug()<<"Client "<<id<<" has disconnected... ";
        Operations("","SignOut");
    }
}

void MyServerHandler::run()
{
    qDebug()<<"Client => "<<id<<" is running on thread =>"<<QThread::currentThreadId();
    socket=new QTcpSocket;
    socket->setSocketDescriptor(id);
    connect(socket,&QTcpSocket::readyRead,this,&MyServerHandler::onReadyRead,Qt::DirectConnection);
    connect(socket,&QTcpSocket::disconnected,this,&MyServerHandler::onDisconnected,Qt::DirectConnection);
    sendMessage("Hello from my server dear client....","Message");
    exec(); //  Start event loop
}
