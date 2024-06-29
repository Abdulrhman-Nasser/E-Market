#include "myclient.h"

MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    // connect(&socket,&QTcpSocket::connected,this,&MyClient::onConnection);
    // connect(&socket,&QTcpSocket::disconnected,this,&MyClient::onDisconnection);
    // connect(&socket,&QTcpSocket::errorOccurred,this,&MyClient::onError);
    // connect(&socket,&QTcpSocket::stateChanged,this,&MyClient::onStateChanged);
    connect(&socket,&QTcpSocket::readyRead,this,&MyClient::onReadyRead);


}

void MyClient::Disconnect()
{
    if(socket.isOpen())
    {
        socket.close();
    }
}

void MyClient::ConnectToDevice(QString ip, qint32 port)
{
    if(socket.isOpen())
    {
        if((this->ip == ip) && (this->port))
        {
            return;
        }
        else
        {
            this->ip= ip;
            this->port=port;
            socket.close();
            socket.connectToHost(this->ip,this->port);
        }
    }
    else
    {
        this->ip= ip;
        this->port=port;
        socket.connectToHost(this->ip,this->port);
    }
}

void MyClient::WriteData(QString str,QString Type)
{
    if(socket.isOpen())
    {
        QJsonObject jsonObject;
        jsonObject["file_type"]=Type;
        jsonObject["file_size"]=str.toUtf8().size();
        jsonObject["file_data"]=str;

        QByteArray byteArray= QJsonDocument(jsonObject).toJson(QJsonDocument::Compact);
        QString header = QString("JsonSize:%1/").arg(byteArray.size());
        byteArray.prepend(header.toUtf8());
        socket.write(byteArray);
    }
}

void MyClient::onReadyRead()
{
    QByteArray byteArray=socket.readAll();
    QString str = QString(byteArray);
    qint32 jsonSize=str.split("/")[0].split(":")[1].toInt();
    QString data = str.right(jsonSize);
    QJsonDocument jsonDoc=QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    qint32 dataSize=jsonObject["file_size"].toInt();
    QString realData = jsonObject["file_data"].toString();
    QString Type = jsonObject["file_type"].toString();
    if(dataSize == realData.size())
    {
        qDebug()<<"Received data from server =>" <<byteArray;
        if(Type == "SuccessLogin")
        {
            emit LoginSuccess(realData);
        }
        else if (Type == "Error")
        {
            emit LoginError(realData);
        }
        else if (Type == "Data")
        {
            emit ProductsUpdate(realData);
        }
        else if(Type == "Address")
        {
            emit addressUpdate(realData);
        }
        else if(Type == "SuccessCheckout")
        {
            emit CheckoutSuccess(realData);
        }
    }
    else
    {
        qDebug()<<"Something wrong with the data!";
    }
}
