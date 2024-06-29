#ifndef INVOICE_H
#define INVOICE_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
class Invoice : public QObject
{
    Q_OBJECT
public:
    explicit Invoice(QObject *parent = nullptr);
    void runCommand(QStringList &command);
    void createHtml(QString);

signals:
};

#endif // INVOICE_H
