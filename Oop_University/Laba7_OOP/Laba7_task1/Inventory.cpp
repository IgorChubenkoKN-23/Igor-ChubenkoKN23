#include "Inventory.h"
#include <iostream>
#include <algorithm>

void Inventory::addProduct(const Product& product) {
    products.push_back(product);
    std::cout << "������� \"" << product.getName() << "\" ������ �� ������.\n";
}

void Inventory::removeProductByName(const std::string& name) {
    auto it = std::remove_if(products.begin(), products.end(),
        [&name](const Product& product) {
            return product.getName() == name;
        });
    if (it != products.end()) {
        products.erase(it, products.end());
        std::cout << "������� \"" << name << "\" ��������.\n";
    }
    else {
        std::cout << "������� \"" << name << "\" �� ��������.\n";
    }
}

void Inventory::updateProduct(const std::string& name, double newPrice, int newQuantity) {
    for (auto& product : products) {
        if (product.getName() == name) {
            product.setPrice(newPrice);
            product.setQuantity(newQuantity);
            std::cout << "������� \"" << name << "\" ��������.\n";
            return;
        }
    }
    std::cout << "������� \"" << name << "\" �� ��������.\n";
}

void Inventory::displayAllProducts() const {
    if (products.empty()) {
        std::cout << "������ �������� �������.\n";
    }
    else {
        for (const auto& product : products) {
            std::cout << product.toString() << '\n';
        }
    }
}

double Inventory::calculateTotalValue() const {
    double totalValue = 0;
    for (const auto& product : products) {
        totalValue += product.getPrice() * product.getQuantity();
    }
    return totalValue;
}
