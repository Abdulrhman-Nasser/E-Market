#ifndef INVOICE_H
#define INVOICE_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include "product.h"
class Invoice : public QObject
{
    Q_OBJECT
public:
    explicit Invoice(QObject *parent = nullptr);
    QString editHtmlFile(const QString &filePath,QString name,QString city, QString dis, QString building, QString apt,QString email,qint32 number,QVector<Product> products);
    void runCommand(QStringList &command);
signals:
};

#endif // INVOICE_H
