#include <QCoreApplication>
#include "myserver.h"
#include <QMutex>
QMutex mux;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyServer server;
    server.StartServer();
    return a.exec();
}
