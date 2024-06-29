#include "myserver.h"

MyServer::MyServer(QObject *parent)
    : QTcpServer{parent},qin(stdin),qout(stdout)
{}

void MyServer::StartServer()
{

    port = 1234;

    this->listen(QHostAddress::Any,port);
    if(this->isListening())
    {
        qout<<"Server is up and listening to port => "<<port<<Qt::endl;
    }
    else
    {
        qout<<"Server can't listen to port => "<<port<<Qt::endl;

    }
}

void MyServer::incomingConnection(qintptr handle)
{
    qDebug()<<"Client"<<handle<<" connecting...";
    MyServerHandler* serverhandler=new MyServerHandler(handle,this);
    connect(serverhandler,&QThread::finished,serverhandler,&QThread::deleteLater); // Clean the resources when done
    serverhandler->start();
}
