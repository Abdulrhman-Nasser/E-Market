#include "invoice.h"

Invoice::Invoice(QObject *parent)
    : QObject{parent}
{}

void Invoice::runCommand(QStringList &command)
{
    QProcess process;
    command.prepend("/c");
    process.start("cmd.exe",command);

    // Wait for the process to finish
    process.waitForFinished();

    // Check if the process finished successfully
    if (process.exitStatus() == QProcess::NormalExit)
    {
        qDebug() << "Command executed successfully.";
    }
    else
    {
        qDebug() << "Failed to execute the command.";
    }
}

void Invoice::createHtml(QString html)
{
    QFile file("invoice.html");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file.";
        return;
    }
    // Write the edited content back to the file
    qDebug()<<"Opened file";
    QTextStream out(&file);
    out << html;
    file.close();
}
