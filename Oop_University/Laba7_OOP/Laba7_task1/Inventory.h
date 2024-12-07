#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    void removeProductByName(const std::string& name);
    void updateProduct(const std::string& name, double newPrice, int newQuantity);
    void displayAllProducts() const;

    double calculateTotalValue() const;
};

#endif