#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
public:
    Product(qint32 id, const QString &category, const QString &name, double price, qint32 quantity);
    // Copy constructor
    Product(const Product &other);
    // Move constructor
    Product(Product &&other) noexcept;
    // Copy assignment operator
    Product& operator=(const Product &other);
    // Move assignment operator
    Product& operator=(Product &&other) noexcept;

    qint32 getId() const;
    void setId(qint32 newId);
    QString getCategory() const;
    void setCategory(const QString &newCategory);
    QString getName() const;
    void setName(const QString &newName);
    double getPrice() const;
    void setPrice(double newPrice);
    qint32 getQuantity() const;
    void setQuantity(qint32 newQuantity);

private:
    qint32 id;
    QString category;
    QString name;
    double price;
    qint32 quantity;

};

#endif // PRODUCT_H
