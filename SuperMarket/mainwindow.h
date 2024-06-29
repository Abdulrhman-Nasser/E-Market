#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <myclient.h>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QTableWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QThread>
#include "product.h"
#include "invoice.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_login_clicked();

    void on_pb_back_clicked();

    void on_pb_cart_clicked();

    void on_pb_signup_clicked();

    void on_pb_checkout_clicked();

    void on_pb_back_2_clicked();

    void on_pb_load_clicked();

    void on_pb_save_clicked();

    void on_pb_order_clicked();

    void on_pb_back_3_clicked();

    void on_pb_display_clicked();

    void on_pb_save_item_clicked();

    void on_pb_delete_clicked();

    void on_tabWidge_currentChanged(int index);

public slots:
    // void onReadyReadDevice(QString data);
    void SuccessLogin(QString);
    void ErrorLogin(QString);
    void UpdateProducts(QString);
    void UpdateAddress(QString);
    void SuccessCheckout(QString);
private:
    void CreateTable(QTableWidget* table,QStringList& headers,QVector<Product>& products);
    void RequestUpdateProducts();
    void UpdateCart(QTableWidget *table);
    void UpdateCarts();
    Ui::MainWindow *ui;
    MyClient client;
    QStringList headers;
    QVector<Product> FruitsProducts;
    QVector<Product> VegiProducts;
    QVector<Product> CannedProducts;
    QVector<Product> DairyProducts;
    QVector<Product> ColdCutsProducts;
    QVector<Product> CleaningProducts;
    QVector<Product> ClothesProducts;
    QVector<Product> SnacksProducts;
    QVector<Product> Cart;
};
#endif // MAINWINDOW_H
