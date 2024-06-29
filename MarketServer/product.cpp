#include "Product.h"

// Default constructor
Product::Product(QObject *parent)
    : QObject(parent), name(""), quantity(0), price(0.0f)
{
}

Product::Product(QString n, qint32 q, double p):name(n),quantity(q),price(p)
{

}

// Copy constructor
Product::Product(const Product &other)
    : QObject(other.parent()), name(other.name), quantity(other.quantity), price(other.price)
{
}

// Move constructor
Product::Product(Product &&other) noexcept
    : QObject(other.parent()), name(std::move(other.name)), quantity(other.quantity), price(other.price)
{
    // Reset the other object's members to a default state
    other.quantity = 0;
    other.price = 0.0f;
}

// Copy assignment operator
Product& Product::operator=(const Product &other)
{
    if (this == &other)
        return *this; // Handle self-assignment

    QObject::setParent(other.parent());
    name = other.name;
    quantity = other.quantity;
    price = other.price;

    return *this;
}

QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &newName)
{
    name = newName;
}

qint32 Product::getQuantity() const
{
    return quantity;
}

void Product::setQuantity(qint32 newQuantity)
{
    quantity = newQuantity;
}

double Product::getPrice() const
{
    return price;
}

void Product::setPrice(double newPrice)
{
    price = newPrice;
}

// Move assignment operator
Product& Product::operator=(Product &&other) noexcept
{
    if (this == &other)
        return *this; // Handle self-assignment

    QObject::setParent(other.parent());
    name = std::move(other.name);
    quantity = other.quantity;
    price = other.price;

    // Reset the other object's members to a default state
    other.quantity = 0;
    other.price = 0.0f;

    return *this;
}
