#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <QString>

class Product : public QObject
{
    Q_OBJECT
public:
    explicit Product(QObject *parent = nullptr);
    Product(QString n,qint32 q,double p);
    Product(const Product &other);            // Copy constructor
    Product(Product &&other) noexcept;        // Move constructor

    // Assignment operators (optional but recommended for complete copy/move semantics)
    Product& operator=(const Product &other); // Copy assignment operator
    Product& operator=(Product &&other) noexcept; // Move assignment operator

    QString getName() const;
    void setName(const QString &newName);
    qint32 getQuantity() const;
    void setQuantity(qint32 newQuantity);
    double getPrice() const;
    void setPrice(double newPrice);

private:
    QString name;
    qint32 quantity;
    double price;
};

#endif // PRODUCT_H
