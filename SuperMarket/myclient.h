#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
class MyClient : public QObject
{
    Q_OBJECT
    QString ip;
    qint32 port;
    QTcpSocket socket;
public:
    explicit MyClient(QObject *parent = nullptr);
    void Disconnect();
    void ConnectToDevice(QString ip,qint32 port);
    void WriteData(QString str,QString Type);
signals:
    void LoginSuccess(QString);
    void LoginError(QString);
    void ProductsUpdate(QString);
    void addressUpdate(QString);
    void CheckoutSuccess(QString);
private slots:
    // void onConnection();
    // void onDisconnection();
    // void onError(QAbstractSocket::SocketError socketError);
    // void onStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();
};

#endif // MYCLIENT_H
