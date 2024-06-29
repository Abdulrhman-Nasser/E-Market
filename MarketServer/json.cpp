#include "json.h"
extern QMutex mux;
Json::Json(QObject *parent)
    : QObject{parent}
{}
void Json::setPath(const QString &newPath)
{
    path = newPath;
}
QJsonArray Json::readFile()
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray byteArray = file.readAll();
        QJsonDocument jsondoc = QJsonDocument::fromJson(byteArray);
        QJsonArray jsonarr = jsondoc.array();
        file.close();
        return jsonarr;
    }
    else
    {
        qDebug()<<"Failed to open file -> "<<path;
    }
}

void Json::writeFile(QJsonArray data)
{
    QFile file(path);
    mux.lock();
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        file.write(QJsonDocument(data).toJson());
        file.close();
    }
    else
    {
        qDebug()<<"Cant open data base file..."<<Qt::endl;
    }
    mux.unlock();
}
