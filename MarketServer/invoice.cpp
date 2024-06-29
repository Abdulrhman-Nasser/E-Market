#include "invoice.h"

Invoice::Invoice(QObject *parent)
    : QObject{parent}
{}

QString Invoice::editHtmlFile(const QString &filePath,QString name,QString city, QString dis, QString building, QString apt,QString email,qint32 number,QVector<Product> products)
{
    // Open the file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file.";
        return "";
    }

    // Read the file content
    QTextStream in(&file);
    QString fileContent = in.readAll();
    file.close();

    // Update the date and invoice number
    fileContent.replace("Date: 12/29/2019", "Date: "+QDate::currentDate().toString("dd/MM/yyyy"));

    // Update name, email, phone number, and address
    fileContent.replace("[Name]", name);
    fileContent.replace("[Email]", email);
    fileContent.replace("Phone: (000-000-0000)", "Phone: "+QString::number(number));
    fileContent.replace("[City, Governrate]", city);
    fileContent.replace("[District]", dis);
    fileContent.replace("[Building]", building);
    fileContent.replace("[Apt]", apt);

    //  Add items
    double total=0;
    int pos = fileContent.indexOf("</tr>", fileContent.indexOf("class=\"heading\""));
    if (pos != -1)
    {
        for(int i=0 ; i<products.size();i++)
        {
            QString newItem = R"(
    <tr class="item">
        <td class="description">)"+products[i].getName()+R"(</td>
        <td class="unit-price">)"+QString::number(products[i].getPrice())+R"(</td>
        <td class="quantity">)"+QString::number(products[i].getQuantity())+R"(</td>
        <td class="price">)"+QString::number(products[i].getPrice()*products[i].getQuantity())+R"(</td>
    </tr>)";
            total +=products[i].getPrice()*products[i].getQuantity();
            fileContent.insert(pos, newItem);
        }
    }
    fileContent.replace("971.56",QString::number(total));
    QFile file1("invoice.html");
    if (!file1.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file1.";
        return "";
    }
    // Write the edited content back to the file1
    qDebug()<<"Opened file1";
    //QDebug()<<fileContent;
    QTextStream out(&file1);
    out << fileContent;
    file1.close();
    return fileContent;
}

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

