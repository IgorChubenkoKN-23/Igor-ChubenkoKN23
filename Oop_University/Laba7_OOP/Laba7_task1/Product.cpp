#include "Product.h"


Product::Product(const std::string& name, const std::string& category, double price, int quantity)
    : name(name), category(category), price(price), quantity(quantity) {}

// Геттери
std::string Product::getName() const {
    return name;
}

std::string Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

// Сеттери
void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setQuantity(int newQuantity) {
    quantity = newQuantity;
}


std::string Product::toString() const {
    std::ostringstream oss;
    oss << "Назва: " << name << ", Категорія: " << category
        << ", Ціна: " << price << " грн, Кількість: " << quantity;
    return oss.str();
}
