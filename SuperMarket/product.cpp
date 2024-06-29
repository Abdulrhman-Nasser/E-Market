#include "product.h"

Product::Product(qint32 id, const QString &category, const QString &name, double price, qint32 quantity) : id(std::move(id)),
    category(category),
    name(name),
    price(price),
    quantity(std::move(quantity))
{}

Product::Product(const Product &other)
    : QObject(other.parent()), id(other.id), category(other.category), name(other.name), price(other.price), quantity(other.quantity)
{
}

Product::Product(Product &&other) noexcept
    : QObject(other.parent()), id(other.id), category(std::move(other.category)), name(std::move(other.name)), price(other.price), quantity(other.quantity)
{
    other.id = 0;
    other.price = 0.0f;
    other.quantity = 0;
}

Product& Product::operator=(const Product &other)
{
    if (this != &other) {
        id = other.id;
        category = other.category;
        name = other.name;
        price = other.price;
        quantity = other.quantity;
        setParent(other.parent());
    }
    return *this;
}

Product& Product::operator=(Product &&other) noexcept
{
    if (this != &other) {
        id = other.id;
        category = std::move(other.category);
        name = std::move(other.name);
        price = other.price;
        quantity = other.quantity;
        setParent(other.parent());

        other.id = 0;
        other.price = 0.0f;
        other.quantity = 0;
    }
    return *this;
}

qint32 Product::getId() const
{
    return id;
}

void Product::setId(qint32 newId)
{
    id = newId;
}

QString Product::getCategory() const
{
    return category;
}

void Product::setCategory(const QString &newCategory)
{
    category = newCategory;
}

QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &newName)
{
    name = newName;
}

double Product::getPrice() const
{
    return price;
}

void Product::setPrice(double newPrice)
{
    price = newPrice;
}

qint32 Product::getQuantity() const
{
    return quantity;
}

void Product::setQuantity(qint32 newQuantity)
{
    quantity = newQuantity;
}


