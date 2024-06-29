#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    headers = { "ID","Product Name", "Quantity", "Price", "Add to Cart" };

    // Setting up the name and icon of the program.
    setWindowTitle("OnlineMarket");
    qDebug()<<QDir::currentPath();
    QIcon windowIcon(QDir::currentPath()+"/../../images/icon.png");
    if (windowIcon.isNull()) {
        qDebug() << "Can't open icon file";
    } else {
        setWindowIcon(windowIcon);
    }


    // connect(&client,&MyClient::ReadyRead,this,&MainWindow::onReadyReadDevice);
    connect(&client,&MyClient::LoginError,this,&MainWindow::ErrorLogin);
    connect(&client,&MyClient::LoginSuccess,this,&MainWindow::SuccessLogin);
    connect(&client,&MyClient::ProductsUpdate,this,&MainWindow::UpdateProducts);
    connect(&client,&MyClient::addressUpdate,this,&MainWindow::UpdateAddress);
    connect(&client,&MyClient::CheckoutSuccess,this,&MainWindow::SuccessCheckout);
    client.ConnectToDevice("192.168.1.2",1234);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::CreateTable(QTableWidget *table, QStringList &headers, QVector<Product> &products)
{
    for(auto i : products)
    {
        qDebug()<<"category => "<<i.getCategory()<<" Name => "<<i.getName()<<" id => "<<i.getId()<<" Price => "<<i.getPrice()<<" Quantity => "<<i.getQuantity();
    }
    // Configure the table widget
    table->clearContents();
    table->setRowCount(0);
    table->setColumnCount(headers.count());
    table->setHorizontalHeaderLabels(headers);

    // Populate the table widget
    for (int row = 0; row < products.size(); ++row) {
        table->insertRow(row);

        QTableWidgetItem *itemID = new QTableWidgetItem(QString::number(products[row].getId()));
        itemID->setFlags(itemID->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 0, itemID);

        QTableWidgetItem *itemName = new QTableWidgetItem(products[row].getName());
        itemName->setFlags(itemName->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 1, itemName);

        QTableWidgetItem *itemQuantity = new QTableWidgetItem(QString::number(products[row].getQuantity()));
        itemQuantity->setFlags(itemQuantity->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 2, itemQuantity);

        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(products[row].getPrice(), 'f', 2));
        itemPrice->setFlags(itemPrice->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 3, itemPrice);


        //  Add the (Add to Cart) button and spin box to all tables except the table in the admin
        if(table!=ui->table_admin)
        {
            // Create a widget to hold the button and spinbox
            QWidget *widget = new QWidget();
            QHBoxLayout *layout = new QHBoxLayout(widget);

            // Create the spinbox
            QSpinBox *spinBox = new QSpinBox();
            spinBox->setRange(1, products[row].getQuantity()); // Set range from 1 to available quantity

            // Create the button
            QPushButton *button = new QPushButton("Add to Cart");
            connect(button, &QPushButton::clicked, this, [=]() {
                // Add to cart logic
                qint32 id = table->item(row,0)->text().toInt();
                QString productName = table->item(row, 1)->text();
                qint32 quantity = spinBox->value();
                spinBox->setValue(1);
                double price = table->item(row,3)->text().toDouble();
                qDebug() << "Adding" << quantity << productName << "(s) "<<" With ID "<<id<<" and price "<<price<<" to cart.";
                for(int i = 0;i<Cart.size();i++)
                {
                    if(Cart[i].getName() == productName)
                    {
                        if( (quantity+Cart[i].getQuantity()) <= table->item(row,2)->text().toInt() )
                        {
                            Cart[i].setQuantity( (Cart[i].getQuantity()+quantity) );
                        }
                        else
                        {
                            QMessageBox::warning(nullptr, "Warning", "Exceeded quantity limit!");
                        }

                        UpdateCarts();
                        RequestUpdateProducts();

                        return;
                    }
                }
                Cart.append(Product(id,"",productName,price,quantity));
                UpdateCarts();
                RequestUpdateProducts();
            });

            // Add spinbox and button to layout
            layout->addWidget(spinBox);
            layout->addWidget(button);
            layout->setContentsMargins(0, 0, 0, 0); // Remove margins to fit items properly
            widget->setLayout(layout);

            // Set the widget in the table
            table->setCellWidget(row, 4, widget);
        }
        else
        {
            table->removeColumn(headers.count()-1);
        }
    }

    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}

void MainWindow::RequestUpdateProducts()
{
    client.WriteData("","GetDataBase");
}

void MainWindow::UpdateCart(QTableWidget *table)
{
    // Configure the table widget
    table->clearContents();
    table->setRowCount(0);
    table->setColumnCount(headers.count());
    QStringList temp = headers;
    temp[4] = "Remove from Cart";
    table->setHorizontalHeaderLabels(temp);

    double sum=0;

    // Populate the table widget
    for (int row = 0; row < Cart.size(); ++row) {
        table->insertRow(row);

        QTableWidgetItem *itemID = new QTableWidgetItem(QString::number(Cart[row].getId()));
        itemID->setFlags(itemID->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 0, itemID);

        QTableWidgetItem *itemName = new QTableWidgetItem(Cart[row].getName());
        itemName->setFlags(itemName->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 1, itemName);

        QTableWidgetItem *itemQuantity = new QTableWidgetItem(QString::number(Cart[row].getQuantity()));
        itemQuantity->setFlags(itemQuantity->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 2, itemQuantity);

        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(Cart[row].getPrice(), 'f', 2));
        itemPrice->setFlags(itemPrice->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, 3, itemPrice);


        // Create a widget to hold the button and spinbox
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);

        // Create the spinbox
        QSpinBox *spinBox = new QSpinBox();
        spinBox->setRange(1, Cart[row].getQuantity()); // Set range from 1 to available quantity

        // Create the button
        QPushButton *button = new QPushButton("Remove from Cart");
        connect(button, &QPushButton::clicked, this, [=]() {
            // Add to cart logic
            qint32 id = table->item(row,0)->text().toInt();
            QString productName = table->item(row, 1)->text();
            qint32 quantity = spinBox->value();
            double price = table->item(row,3)->text().toDouble();
            qDebug() << "Removing " << quantity << productName << "(s) "<<" With ID "<<id<<" and price "<<price<<" to cart.";
            if(quantity >= table->item(row,2)->text().toInt())
            {
                Cart.remove(row,1);
            }
            else
            {
                Cart[row].setQuantity( (Cart[row].getQuantity()-quantity) );
            }
            UpdateCarts();
            RequestUpdateProducts();
        });

        // Add spinbox and button to layout
        layout->addWidget(spinBox);
        layout->addWidget(button);
        layout->setContentsMargins(0, 0, 0, 0); // Remove margins to fit items properly
        widget->setLayout(layout);

        // Set the widget in the table
        table->setCellWidget(row, 4, widget);

        // Calculate sum for the checkout
        sum = sum + (Cart[row].getPrice()*Cart[row].getQuantity());
    }


    // Display total in check out cart
    if(table == ui->table_Cart9)
    {
        table->insertRow(Cart.size());
        QTableWidgetItem *total = new QTableWidgetItem("Total");
        total->setFlags(total->flags() & ~Qt::ItemIsEditable);
        QFont font = total->font();
        font.setBold(true);
        total->setFont(font);
        table->setItem(Cart.size(), 1, total);


        QTableWidgetItem *totalPrice = new QTableWidgetItem(QString::number(sum, 'f', 2));
        totalPrice->setFlags(totalPrice->flags() & ~Qt::ItemIsEditable);
        table->setItem(Cart.size(), 3, totalPrice);
    }

    // Fit the table to the content
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}

void MainWindow::UpdateCarts()
{
    // Update all the carts table
    UpdateCart(ui->tableCart1);
    UpdateCart(ui->table_Cart2);
    UpdateCart(ui->table_Cart3);
    UpdateCart(ui->table_Cart4);
    UpdateCart(ui->table_Cart5);
    UpdateCart(ui->table_Cart6);
    UpdateCart(ui->table_Cart7);
    UpdateCart(ui->table_Cart8);
    UpdateCart(ui->table_Cart9);
}

void MainWindow::on_pb_login_clicked()
{
    QString username = ui->LE_username->text();
    QString password = ui->LE_password->text();
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::critical(nullptr, "Error", "Enter username and password.");
    }
    else
    {
        ui->LE_password->clear();
        ui->LE_username->clear();
        client.WriteData(username+"\n"+password,"Login");
    }
}

void MainWindow::SuccessLogin(QString auth)
{
    if(auth == "Admin")
    {
        RequestUpdateProducts();
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(auth == "User")
    {
        RequestUpdateProducts();
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::ErrorLogin(QString msg)
{
    QMessageBox::critical(nullptr, "Error", msg);
}

void MainWindow::UpdateProducts(QString data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    QJsonArray AllProducts = doc.array();
    FruitsProducts.clear();
    VegiProducts.clear();
    CannedProducts.clear();
    DairyProducts.clear();
    ColdCutsProducts.clear();
    CleaningProducts.clear();
    ClothesProducts.clear();
    SnacksProducts.clear();
    for(int i=0 ; i<AllProducts.size();i++)
    {
        QJsonObject jsonobj= AllProducts[i].toObject();
        QString cat = jsonobj["category"].toString();
        QString name=jsonobj["name"].toString();
        qint32 id = jsonobj["id"].toInt();
        double price = jsonobj["price"].toDouble();
        qint32 quantity = jsonobj["quantity"].toInt();

        if(cat == "Fruits")
        {
            FruitsProducts.append(Product(id,cat,name,price,quantity));
        }
        else if(cat == "Vegetables")
        {
            VegiProducts.append(Product(id,cat,name,price,quantity));
        }
        else if(cat == "Canned foods")
        {
            CannedProducts.append(Product(id,cat,name,price,quantity));
        }
        else if(cat == "Dairy products")
        {
            DairyProducts.append(Product(id,cat,name,price,quantity));
        }
        else if(cat == "Cold cuts")
        {
            ColdCutsProducts.append(Product(id,cat,name,price,quantity));
        }
        else if(cat == "Cleaning products")
        {
            CleaningProducts.append(Product(id,cat,name,price,quantity));
        }
        else if(cat == "Clothes")
        {
            ClothesProducts.append(Product(id,cat,name,price,quantity));
        }
        else if(cat == "Snacks")
        {
            SnacksProducts.append(Product(id,cat,name,price,quantity));
        }

    }
    CreateTable(ui->table_fruits,headers,FruitsProducts);
    CreateTable(ui->table_Canned,headers,CannedProducts);
    CreateTable(ui->table_Cleaning,headers,CleaningProducts);
    CreateTable(ui->table_Clothes,headers,ClothesProducts);
    CreateTable(ui->table_Cold,headers,ColdCutsProducts);
    CreateTable(ui->table_Dairy,headers,DairyProducts);
    CreateTable(ui->table_Vegi,headers,VegiProducts);
    CreateTable(ui->table_Snacks,headers,SnacksProducts);
    QVector<Product> AllProduct = (FruitsProducts+CannedProducts+CleaningProducts+ClothesProducts+ColdCutsProducts+DairyProducts+VegiProducts+SnacksProducts);
    CreateTable(ui->table_admin,headers,AllProduct);
}

void MainWindow::UpdateAddress(QString data)
{
    if(data == "\n\n\n\n\n\n")
    {
        QMessageBox::warning(nullptr,"Warning","No Address Saved");
        return;
    }
    QStringList list = data.split('\n');
    QString city = list[0];
    QString gov=list[1];
    QString dis=list[2];
    QString building=list[3];
    QString apt = list[4];
    QString email = list[5];
    qint32 number = list[6].toInt();
    ui->LE_city->setText(city);
    ui->LE_gov->setText(gov);
    ui->LE_dis->setText(dis);
    ui->LE_building->setText(building);
    ui->LE_apt->setText(apt);
    ui->LE_email->setText(email);
    ui->LE_number->setText(QString::number(number));
}

void MainWindow::SuccessCheckout(QString html)
{
    Cart.clear();
    UpdateCarts();
    Invoice invoice;
    invoice.createHtml(html);
    QStringList command;
    command<<"wkhtmltopdf --enable-local-file-access "+QDir::currentPath()+"/invoice.html "+QDir::currentPath()+"/tst.pdf";
    invoice.runCommand(command);
}


void MainWindow::on_pb_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    client.WriteData("","SignOut");
}


void MainWindow::on_pb_cart_clicked()
{
    RequestUpdateProducts();
}


void MainWindow::on_pb_signup_clicked()
{
    QString username = ui->LE_username->text();
    QString password = ui->LE_password->text();
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::critical(nullptr, "Error", "Enter username and password.");
    }
    else
    {
        ui->LE_password->clear();
        ui->LE_username->clear();
        client.WriteData(username+"\n"+password,"Signup");
    }
}


void MainWindow::on_pb_checkout_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pb_back_2_clicked()
{
    RequestUpdateProducts();
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pb_load_clicked()
{
    client.WriteData("","Get_Address");
}


void MainWindow::on_pb_save_clicked()
{
    bool num;
    qint32 number = ui->LE_number->text().toInt(&num);
    if(!num)
    {
        QMessageBox::critical(nullptr,"Error","Enter valid number!");
        return;
    }
    QString data=ui->LE_city->text()+"\n"+ui->LE_gov->text()+"\n"+ui->LE_dis->text()+"\n"+ui->LE_building->text()+"\n"+ui->LE_apt->text()+"\n"+ui->LE_email->text()+"\n"+ui->LE_number->text();
    if(data == "\n\n\n\n")
    {
        QMessageBox::warning(nullptr,"Warning","No Address to save");
        return;
    }
    client.WriteData(data,"Save_Address");
}


void MainWindow::on_pb_order_clicked()
{
    if(Cart.isEmpty())
    {
        QMessageBox::critical(nullptr,"Error","Nothing in cart");
        return;
    }
    QJsonArray jsonarr;
    for(int i=0; i<Cart.size(); i++)
    {
        QJsonObject jsonobj;
        jsonobj["id"] = Cart[i].getId();
        qDebug()<<jsonobj["id"];
        jsonobj["quantity"] = Cart[i].getQuantity();
        jsonarr.append(jsonobj);
    }
    QJsonDocument doc;
    doc.setArray(jsonarr);
    QString data(doc.toJson());
    client.WriteData(data,"CheckOut");

}


void MainWindow::on_pb_back_3_clicked()
{
    client.WriteData("","SignOut");
    ui->stackedWidget->setCurrentIndex(0);
    //client.WriteData("","SignOut");
}


void MainWindow::on_pb_display_clicked()
{
    RequestUpdateProducts();
}


void MainWindow::on_pb_save_item_clicked()
{
    if(!(ui->LE_cat->text().isEmpty() || ui->LE_name->text().isEmpty() || ui->LE_id->text().isEmpty() || ui->LE_price->text().isEmpty() || ui->LE_quantity->text().isEmpty()))
    {

        QString cat = ui->LE_cat->text();
        QString name = ui->LE_name->text();
        qint32 id = ui->LE_id->text().toInt();
        double price = ui->LE_price->text().toDouble();
        qint32 quantity = ui->LE_quantity->text().toInt();
        QJsonObject jsonobj;
        jsonobj["category"] = cat;
        jsonobj["id"] = id;
        jsonobj["name"] = name;
        jsonobj["price"] = price;
        jsonobj["quantity"] = quantity;
        QJsonDocument jsondoc(jsonobj);
        QString data = jsondoc.toJson(QJsonDocument::Compact);
        client.WriteData(data,"New_Product");
        ui->LE_cat->clear();
        ui->LE_name->clear();
        ui->LE_id->clear();
        ui->LE_price->clear();
        ui->LE_quantity->clear();
    }
    else
    {
        QMessageBox::critical(nullptr,"Error","Please fill out all data!");
    }
}


void MainWindow::on_pb_delete_clicked()
{
    if(!(ui->LE_nameD->text().isEmpty() || ui->LE_idD->text().isEmpty()))
    {
        QString name = ui->LE_nameD->text();
        qint32 id = ui->LE_idD->text().toInt();
        QJsonObject jsonobj;
        jsonobj["id"] = id;
        jsonobj["name"] = name;
        QJsonDocument jsondoc(jsonobj);
        QString data = jsondoc.toJson(QJsonDocument::Compact);
        client.WriteData(data,"Delete_Product");
        ui->LE_nameD->clear();
        ui->LE_idD->clear();
    }
    else
    {
        QMessageBox::critical(nullptr,"Error","Please fill out all data!");
    }
}


void MainWindow::on_tabWidge_currentChanged(int index)
{
    RequestUpdateProducts();
}

