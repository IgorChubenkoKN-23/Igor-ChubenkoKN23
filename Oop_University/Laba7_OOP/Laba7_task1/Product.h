#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sstream>

class Product {
private:
    std::string name;
    std::string category;
    double price;
    int quantity;

public:
    
    Product(const std::string& name, const std::string& category, double price, int quantity);

   
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getQuantity() const;

    void setPrice(double newPrice);
    void setQuantity(int newQuantity);

    std::string toString() const;
};

#endif