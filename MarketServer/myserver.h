#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTextStream>
#include <QDebug>
#include <myserverhandler.h>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);
    void StartServer();

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle);
private:
    QTextStream qin;
    QTextStream qout;
    qint32 port;
};

#endif // MYSERVER_H
