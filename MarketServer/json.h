#ifndef JSON_H
#define JSON_H

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QMutex>
class Json : public QObject
{
    Q_OBJECT
    QString path;
public:
    explicit Json(QObject *parent = nullptr);
    QJsonArray readFile();
    void writeFile(QJsonArray data);
    void setPath(const QString &newPath);

signals:
};

#endif // JSON_H
