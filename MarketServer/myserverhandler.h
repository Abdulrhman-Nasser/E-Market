#ifndef MYSERVERHANDLER_H
#define MYSERVERHANDLER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDir>
#include "json.h"
#include "product.h"
#include "invoice.h"
class MyServerHandler : public QThread
{
    Q_OBJECT
public:
    explicit MyServerHandler(qint32 ID,QObject *parent = nullptr);
    void sendMessage(QString,QString);
    void Operations(QString,QString);
    void Login(QString username,qint32 pass);
public slots:
    void onReadyRead();
    void onDisconnected();
private:
    qint32 id;
    QTcpSocket* socket;
    Json LoginData;
    Json ProductsDB;
    // QThread interface
protected:
    void run();
private:
    QString name;
    qint32 pass;
    QVector<Product> invoceProducts;
    Invoice invoice;
};

#endif // MYSERVERHANDLER_H
