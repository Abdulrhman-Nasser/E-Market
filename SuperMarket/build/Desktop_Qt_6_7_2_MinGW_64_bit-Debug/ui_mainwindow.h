/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionada;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Login;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LE_username;
    QLineEdit *LE_password;
    QSplitter *splitter;
    QPushButton *pb_login;
    QPushButton *pb_signup;
    QWidget *Admin;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *LE_cat;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *LE_name;
    QLineEdit *LE_id;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *LE_price;
    QLineEdit *LE_quantity;
    QPushButton *pb_save_item;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *LE_nameD;
    QLineEdit *LE_idD;
    QPushButton *pb_delete;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *table_admin;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pb_display;
    QPushButton *pb_clear;
    QPushButton *pb_back_3;
    QWidget *User;
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QTabWidget *tabWidge;
    QWidget *tab;
    QSplitter *splitter_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableWidget *table_fruits;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_5;
    QTableWidget *tableCart1;
    QWidget *tab_2;
    QSplitter *splitter_6;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_16;
    QTableWidget *table_Vegi;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_17;
    QTableWidget *table_Cart2;
    QWidget *tab_5;
    QSplitter *splitter_7;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_18;
    QTableWidget *table_Canned;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_19;
    QTableWidget *table_Cart3;
    QWidget *tab_6;
    QSplitter *splitter_8;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_20;
    QTableWidget *table_Dairy;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_21;
    QTableWidget *table_Cart4;
    QWidget *tab_7;
    QSplitter *splitter_9;
    QGroupBox *groupBox_20;
    QGridLayout *gridLayout_22;
    QTableWidget *table_Cold;
    QGroupBox *groupBox_21;
    QGridLayout *gridLayout_23;
    QTableWidget *table_Cart5;
    QWidget *tab_8;
    QSplitter *splitter_10;
    QGroupBox *groupBox_22;
    QGridLayout *gridLayout_24;
    QTableWidget *table_Clothes;
    QGroupBox *groupBox_23;
    QGridLayout *gridLayout_25;
    QTableWidget *table_Cart6;
    QWidget *tab_9;
    QSplitter *splitter_11;
    QGroupBox *groupBox_24;
    QGridLayout *gridLayout_26;
    QTableWidget *table_Snacks;
    QGroupBox *groupBox_25;
    QGridLayout *gridLayout_27;
    QTableWidget *table_Cart7;
    QWidget *tab_10;
    QSplitter *splitter_5;
    QSplitter *splitter_12;
    QGroupBox *groupBox_26;
    QGridLayout *gridLayout_28;
    QTableWidget *table_Cleaning;
    QGroupBox *groupBox_27;
    QGridLayout *gridLayout_29;
    QTableWidget *table_Cart8;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_back;
    QPushButton *pb_checkout;
    QWidget *Checkout;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_6;
    QTableWidget *table_Cart9;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *LE_email;
    QLineEdit *LE_number;
    QLineEdit *LE_city;
    QLineEdit *LE_gov;
    QLineEdit *LE_dis;
    QLineEdit *LE_building;
    QLineEdit *LE_apt;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_order;
    QPushButton *pb_back_2;
    QPushButton *pb_save;
    QPushButton *pb_load;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(814, 544);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1600000, 1600000));
        actionada = new QAction(MainWindow);
        actionada->setObjectName("actionada");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 801, 521));
        Login = new QWidget();
        Login->setObjectName("Login");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(Login);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBox = new QGroupBox(Login);
        groupBox->setObjectName("groupBox");
        groupBox->setEnabled(true);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/supermarket-groceries-in-the-basket.png")));
        label->setScaledContents(true);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName("layoutWidget");
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LE_username = new QLineEdit(layoutWidget);
        LE_username->setObjectName("LE_username");

        horizontalLayout->addWidget(LE_username);

        LE_password = new QLineEdit(layoutWidget);
        LE_password->setObjectName("LE_password");

        horizontalLayout->addWidget(LE_password);

        splitter_2->addWidget(layoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        pb_login = new QPushButton(splitter);
        pb_login->setObjectName("pb_login");
        splitter->addWidget(pb_login);
        pb_signup = new QPushButton(splitter);
        pb_signup->setObjectName("pb_signup");
        splitter->addWidget(pb_signup);
        splitter_2->addWidget(splitter);

        gridLayout_4->addWidget(splitter_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        stackedWidget->addWidget(Login);
        Admin = new QWidget();
        Admin->setObjectName("Admin");
        groupBox_4 = new QGroupBox(Admin);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(0, 10, 401, 271));
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setObjectName("gridLayout_8");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        LE_cat = new QLineEdit(groupBox_4);
        LE_cat->setObjectName("LE_cat");

        verticalLayout_3->addWidget(LE_cat);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        LE_name = new QLineEdit(groupBox_4);
        LE_name->setObjectName("LE_name");

        horizontalLayout_4->addWidget(LE_name);

        LE_id = new QLineEdit(groupBox_4);
        LE_id->setObjectName("LE_id");

        horizontalLayout_4->addWidget(LE_id);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        LE_price = new QLineEdit(groupBox_4);
        LE_price->setObjectName("LE_price");

        horizontalLayout_5->addWidget(LE_price);

        LE_quantity = new QLineEdit(groupBox_4);
        LE_quantity->setObjectName("LE_quantity");

        horizontalLayout_5->addWidget(LE_quantity);


        verticalLayout_3->addLayout(horizontalLayout_5);

        pb_save_item = new QPushButton(groupBox_4);
        pb_save_item->setObjectName("pb_save_item");

        verticalLayout_3->addWidget(pb_save_item);


        gridLayout_8->addLayout(verticalLayout_3, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(Admin);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(-1, 300, 401, 161));
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setObjectName("gridLayout_9");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        LE_nameD = new QLineEdit(groupBox_5);
        LE_nameD->setObjectName("LE_nameD");

        horizontalLayout_6->addWidget(LE_nameD);

        LE_idD = new QLineEdit(groupBox_5);
        LE_idD->setObjectName("LE_idD");

        horizontalLayout_6->addWidget(LE_idD);


        verticalLayout_4->addLayout(horizontalLayout_6);

        pb_delete = new QPushButton(groupBox_5);
        pb_delete->setObjectName("pb_delete");

        verticalLayout_4->addWidget(pb_delete);


        gridLayout_9->addLayout(verticalLayout_4, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(Admin);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(420, 10, 381, 451));
        gridLayout_10 = new QGridLayout(groupBox_6);
        gridLayout_10->setObjectName("gridLayout_10");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        table_admin = new QTableWidget(groupBox_6);
        table_admin->setObjectName("table_admin");

        verticalLayout_5->addWidget(table_admin);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pb_display = new QPushButton(groupBox_6);
        pb_display->setObjectName("pb_display");

        horizontalLayout_7->addWidget(pb_display);

        pb_clear = new QPushButton(groupBox_6);
        pb_clear->setObjectName("pb_clear");

        horizontalLayout_7->addWidget(pb_clear);


        verticalLayout_5->addLayout(horizontalLayout_7);


        gridLayout_10->addLayout(verticalLayout_5, 0, 0, 1, 1);

        pb_back_3 = new QPushButton(Admin);
        pb_back_3->setObjectName("pb_back_3");
        pb_back_3->setGeometry(QRect(570, 470, 80, 24));
        stackedWidget->addWidget(Admin);
        User = new QWidget();
        User->setObjectName("User");
        gridLayout = new QGridLayout(User);
        gridLayout->setObjectName("gridLayout");
        splitter_3 = new QSplitter(User);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Vertical);
        tabWidge = new QTabWidget(splitter_3);
        tabWidge->setObjectName("tabWidge");
        tabWidge->setEnabled(true);
        tabWidge->setTabPosition(QTabWidget::West);
        tab = new QWidget();
        tab->setObjectName("tab");
        splitter_4 = new QSplitter(tab);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setGeometry(QRect(10, 0, 741, 441));
        splitter_4->setOrientation(Qt::Horizontal);
        groupBox_2 = new QGroupBox(splitter_4);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        table_fruits = new QTableWidget(groupBox_2);
        table_fruits->setObjectName("table_fruits");

        gridLayout_2->addWidget(table_fruits, 0, 0, 1, 1);

        splitter_4->addWidget(groupBox_2);
        groupBox_10 = new QGroupBox(splitter_4);
        groupBox_10->setObjectName("groupBox_10");
        gridLayout_5 = new QGridLayout(groupBox_10);
        gridLayout_5->setObjectName("gridLayout_5");
        tableCart1 = new QTableWidget(groupBox_10);
        tableCart1->setObjectName("tableCart1");

        gridLayout_5->addWidget(tableCart1, 0, 0, 1, 1);

        splitter_4->addWidget(groupBox_10);
        tabWidge->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        splitter_6 = new QSplitter(tab_2);
        splitter_6->setObjectName("splitter_6");
        splitter_6->setGeometry(QRect(10, 0, 741, 441));
        splitter_6->setOrientation(Qt::Horizontal);
        groupBox_14 = new QGroupBox(splitter_6);
        groupBox_14->setObjectName("groupBox_14");
        gridLayout_16 = new QGridLayout(groupBox_14);
        gridLayout_16->setObjectName("gridLayout_16");
        table_Vegi = new QTableWidget(groupBox_14);
        table_Vegi->setObjectName("table_Vegi");

        gridLayout_16->addWidget(table_Vegi, 0, 0, 1, 1);

        splitter_6->addWidget(groupBox_14);
        groupBox_15 = new QGroupBox(splitter_6);
        groupBox_15->setObjectName("groupBox_15");
        gridLayout_17 = new QGridLayout(groupBox_15);
        gridLayout_17->setObjectName("gridLayout_17");
        table_Cart2 = new QTableWidget(groupBox_15);
        table_Cart2->setObjectName("table_Cart2");

        gridLayout_17->addWidget(table_Cart2, 0, 0, 1, 1);

        splitter_6->addWidget(groupBox_15);
        tabWidge->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        splitter_7 = new QSplitter(tab_5);
        splitter_7->setObjectName("splitter_7");
        splitter_7->setGeometry(QRect(10, 0, 741, 441));
        splitter_7->setOrientation(Qt::Horizontal);
        groupBox_16 = new QGroupBox(splitter_7);
        groupBox_16->setObjectName("groupBox_16");
        gridLayout_18 = new QGridLayout(groupBox_16);
        gridLayout_18->setObjectName("gridLayout_18");
        table_Canned = new QTableWidget(groupBox_16);
        table_Canned->setObjectName("table_Canned");

        gridLayout_18->addWidget(table_Canned, 0, 0, 1, 1);

        splitter_7->addWidget(groupBox_16);
        groupBox_17 = new QGroupBox(splitter_7);
        groupBox_17->setObjectName("groupBox_17");
        gridLayout_19 = new QGridLayout(groupBox_17);
        gridLayout_19->setObjectName("gridLayout_19");
        table_Cart3 = new QTableWidget(groupBox_17);
        table_Cart3->setObjectName("table_Cart3");

        gridLayout_19->addWidget(table_Cart3, 0, 0, 1, 1);

        splitter_7->addWidget(groupBox_17);
        tabWidge->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        splitter_8 = new QSplitter(tab_6);
        splitter_8->setObjectName("splitter_8");
        splitter_8->setGeometry(QRect(10, 0, 741, 441));
        splitter_8->setOrientation(Qt::Horizontal);
        groupBox_18 = new QGroupBox(splitter_8);
        groupBox_18->setObjectName("groupBox_18");
        gridLayout_20 = new QGridLayout(groupBox_18);
        gridLayout_20->setObjectName("gridLayout_20");
        table_Dairy = new QTableWidget(groupBox_18);
        table_Dairy->setObjectName("table_Dairy");

        gridLayout_20->addWidget(table_Dairy, 0, 0, 1, 1);

        splitter_8->addWidget(groupBox_18);
        groupBox_19 = new QGroupBox(splitter_8);
        groupBox_19->setObjectName("groupBox_19");
        gridLayout_21 = new QGridLayout(groupBox_19);
        gridLayout_21->setObjectName("gridLayout_21");
        table_Cart4 = new QTableWidget(groupBox_19);
        table_Cart4->setObjectName("table_Cart4");

        gridLayout_21->addWidget(table_Cart4, 0, 0, 1, 1);

        splitter_8->addWidget(groupBox_19);
        tabWidge->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        splitter_9 = new QSplitter(tab_7);
        splitter_9->setObjectName("splitter_9");
        splitter_9->setGeometry(QRect(10, 0, 741, 441));
        splitter_9->setOrientation(Qt::Horizontal);
        groupBox_20 = new QGroupBox(splitter_9);
        groupBox_20->setObjectName("groupBox_20");
        gridLayout_22 = new QGridLayout(groupBox_20);
        gridLayout_22->setObjectName("gridLayout_22");
        table_Cold = new QTableWidget(groupBox_20);
        table_Cold->setObjectName("table_Cold");

        gridLayout_22->addWidget(table_Cold, 0, 0, 1, 1);

        splitter_9->addWidget(groupBox_20);
        groupBox_21 = new QGroupBox(splitter_9);
        groupBox_21->setObjectName("groupBox_21");
        gridLayout_23 = new QGridLayout(groupBox_21);
        gridLayout_23->setObjectName("gridLayout_23");
        table_Cart5 = new QTableWidget(groupBox_21);
        table_Cart5->setObjectName("table_Cart5");

        gridLayout_23->addWidget(table_Cart5, 0, 0, 1, 1);

        splitter_9->addWidget(groupBox_21);
        tabWidge->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        splitter_10 = new QSplitter(tab_8);
        splitter_10->setObjectName("splitter_10");
        splitter_10->setGeometry(QRect(10, 0, 741, 441));
        splitter_10->setOrientation(Qt::Horizontal);
        groupBox_22 = new QGroupBox(splitter_10);
        groupBox_22->setObjectName("groupBox_22");
        gridLayout_24 = new QGridLayout(groupBox_22);
        gridLayout_24->setObjectName("gridLayout_24");
        table_Clothes = new QTableWidget(groupBox_22);
        table_Clothes->setObjectName("table_Clothes");

        gridLayout_24->addWidget(table_Clothes, 0, 0, 1, 1);

        splitter_10->addWidget(groupBox_22);
        groupBox_23 = new QGroupBox(splitter_10);
        groupBox_23->setObjectName("groupBox_23");
        gridLayout_25 = new QGridLayout(groupBox_23);
        gridLayout_25->setObjectName("gridLayout_25");
        table_Cart6 = new QTableWidget(groupBox_23);
        table_Cart6->setObjectName("table_Cart6");

        gridLayout_25->addWidget(table_Cart6, 0, 0, 1, 1);

        splitter_10->addWidget(groupBox_23);
        tabWidge->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        splitter_11 = new QSplitter(tab_9);
        splitter_11->setObjectName("splitter_11");
        splitter_11->setGeometry(QRect(10, 0, 741, 441));
        splitter_11->setOrientation(Qt::Horizontal);
        groupBox_24 = new QGroupBox(splitter_11);
        groupBox_24->setObjectName("groupBox_24");
        gridLayout_26 = new QGridLayout(groupBox_24);
        gridLayout_26->setObjectName("gridLayout_26");
        table_Snacks = new QTableWidget(groupBox_24);
        table_Snacks->setObjectName("table_Snacks");

        gridLayout_26->addWidget(table_Snacks, 0, 0, 1, 1);

        splitter_11->addWidget(groupBox_24);
        groupBox_25 = new QGroupBox(splitter_11);
        groupBox_25->setObjectName("groupBox_25");
        gridLayout_27 = new QGridLayout(groupBox_25);
        gridLayout_27->setObjectName("gridLayout_27");
        table_Cart7 = new QTableWidget(groupBox_25);
        table_Cart7->setObjectName("table_Cart7");

        gridLayout_27->addWidget(table_Cart7, 0, 0, 1, 1);

        splitter_11->addWidget(groupBox_25);
        tabWidge->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        splitter_5 = new QSplitter(tab_10);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setGeometry(QRect(10, 0, 741, 441));
        splitter_5->setOrientation(Qt::Horizontal);
        splitter_12 = new QSplitter(splitter_5);
        splitter_12->setObjectName("splitter_12");
        splitter_12->setOrientation(Qt::Horizontal);
        groupBox_26 = new QGroupBox(splitter_12);
        groupBox_26->setObjectName("groupBox_26");
        gridLayout_28 = new QGridLayout(groupBox_26);
        gridLayout_28->setObjectName("gridLayout_28");
        table_Cleaning = new QTableWidget(groupBox_26);
        table_Cleaning->setObjectName("table_Cleaning");

        gridLayout_28->addWidget(table_Cleaning, 0, 0, 1, 1);

        splitter_12->addWidget(groupBox_26);
        groupBox_27 = new QGroupBox(splitter_12);
        groupBox_27->setObjectName("groupBox_27");
        gridLayout_29 = new QGridLayout(groupBox_27);
        gridLayout_29->setObjectName("gridLayout_29");
        table_Cart8 = new QTableWidget(groupBox_27);
        table_Cart8->setObjectName("table_Cart8");

        gridLayout_29->addWidget(table_Cart8, 0, 0, 1, 1);

        splitter_12->addWidget(groupBox_27);
        splitter_5->addWidget(splitter_12);
        tabWidge->addTab(tab_10, QString());
        splitter_3->addWidget(tabWidge);
        layoutWidget1 = new QWidget(splitter_3);
        layoutWidget1->setObjectName("layoutWidget1");
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_back = new QPushButton(layoutWidget1);
        pb_back->setObjectName("pb_back");

        horizontalLayout_2->addWidget(pb_back);

        pb_checkout = new QPushButton(layoutWidget1);
        pb_checkout->setObjectName("pb_checkout");

        horizontalLayout_2->addWidget(pb_checkout);

        splitter_3->addWidget(layoutWidget1);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);

        stackedWidget->addWidget(User);
        Checkout = new QWidget();
        Checkout->setObjectName("Checkout");
        groupBox_11 = new QGroupBox(Checkout);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(410, 10, 368, 441));
        gridLayout_6 = new QGridLayout(groupBox_11);
        gridLayout_6->setObjectName("gridLayout_6");
        table_Cart9 = new QTableWidget(groupBox_11);
        table_Cart9->setObjectName("table_Cart9");

        gridLayout_6->addWidget(table_Cart9, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(Checkout);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 10, 371, 281));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setObjectName("gridLayout_7");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        LE_email = new QLineEdit(groupBox_3);
        LE_email->setObjectName("LE_email");

        verticalLayout->addWidget(LE_email);

        LE_number = new QLineEdit(groupBox_3);
        LE_number->setObjectName("LE_number");

        verticalLayout->addWidget(LE_number);

        LE_city = new QLineEdit(groupBox_3);
        LE_city->setObjectName("LE_city");

        verticalLayout->addWidget(LE_city);

        LE_gov = new QLineEdit(groupBox_3);
        LE_gov->setObjectName("LE_gov");

        verticalLayout->addWidget(LE_gov);

        LE_dis = new QLineEdit(groupBox_3);
        LE_dis->setObjectName("LE_dis");

        verticalLayout->addWidget(LE_dis);

        LE_building = new QLineEdit(groupBox_3);
        LE_building->setObjectName("LE_building");

        verticalLayout->addWidget(LE_building);

        LE_apt = new QLineEdit(groupBox_3);
        LE_apt->setObjectName("LE_apt");

        verticalLayout->addWidget(LE_apt);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pb_order = new QPushButton(groupBox_3);
        pb_order->setObjectName("pb_order");

        horizontalLayout_3->addWidget(pb_order);

        pb_back_2 = new QPushButton(groupBox_3);
        pb_back_2->setObjectName("pb_back_2");

        horizontalLayout_3->addWidget(pb_back_2);

        pb_save = new QPushButton(groupBox_3);
        pb_save->setObjectName("pb_save");

        horizontalLayout_3->addWidget(pb_save);

        pb_load = new QPushButton(groupBox_3);
        pb_load->setObjectName("pb_load");

        horizontalLayout_3->addWidget(pb_load);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_7->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(Checkout);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pb_clear, &QPushButton::clicked, table_admin, qOverload<>(&QTableWidget::clear));

        stackedWidget->setCurrentIndex(1);
        tabWidge->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionada->setText(QCoreApplication::translate("MainWindow", "ada", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label->setText(QString());
        LE_username->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        LE_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pb_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pb_signup->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
        LE_cat->setPlaceholderText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        LE_name->setPlaceholderText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        LE_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        LE_price->setPlaceholderText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        LE_quantity->setPlaceholderText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        pb_save_item->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Delete item", nullptr));
        LE_nameD->setPlaceholderText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        LE_idD->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        pb_delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Display", nullptr));
        pb_display->setText(QCoreApplication::translate("MainWindow", "Display", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pb_back_3->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab), QCoreApplication::translate("MainWindow", "Fruits", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Vegitables", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Canned Foods", nullptr));
        groupBox_18->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_19->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Daity", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_21->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Cold Cuts", nullptr));
        groupBox_22->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_23->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Clothes", nullptr));
        groupBox_24->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_25->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Snakes", nullptr));
        groupBox_26->setTitle(QCoreApplication::translate("MainWindow", "Products", nullptr));
        groupBox_27->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        tabWidge->setTabText(tabWidge->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Cleaning", nullptr));
        pb_back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pb_checkout->setText(QCoreApplication::translate("MainWindow", "Checkout", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "Cart", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Address", nullptr));
        LE_email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        LE_number->setPlaceholderText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        LE_city->setPlaceholderText(QCoreApplication::translate("MainWindow", "City", nullptr));
        LE_gov->setPlaceholderText(QCoreApplication::translate("MainWindow", "Governorate", nullptr));
        LE_dis->setPlaceholderText(QCoreApplication::translate("MainWindow", "District", nullptr));
        LE_building->setPlaceholderText(QCoreApplication::translate("MainWindow", "Building no.", nullptr));
        LE_apt->setPlaceholderText(QCoreApplication::translate("MainWindow", "Apt. number", nullptr));
        pb_order->setText(QCoreApplication::translate("MainWindow", "Order", nullptr));
        pb_back_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pb_save->setText(QCoreApplication::translate("MainWindow", "Save Address", nullptr));
        pb_load->setText(QCoreApplication::translate("MainWindow", "Load Address", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
