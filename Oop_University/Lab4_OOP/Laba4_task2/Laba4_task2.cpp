#include <iostream>
#include <string>
#include <Windows.h>
#include <stdexcept>

class Product {
protected:
    std::string name;
    double price;
    int stock;

public:
    Product(const std::string& name, double price, int stock)
        : name(name) {
        setPrice(price);
        setStock(stock);
    }

    std::string getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }

    double getPrice() const { return price; }
    virtual void setPrice(double price) {
        if (price < 0)
            throw std::invalid_argument("Ціна не може бути від'ємною.");
        this->price = price;
    }

    int getStock() const { return stock; }
    virtual void setStock(int stock) {
        if (stock < 0)
            throw std::invalid_argument("Кількість на складі не може бути від'ємною.");
        this->stock = stock;
    }

    virtual void display() const = 0;
};

class Furniture : public Product {
private:
    std::string material;
    std::string color;

public:
    Furniture(const std::string& name, double price, int stock, const std::string& material, const std::string& color)
        : Product(name, price, stock), material(material), color(color) {}

    std::string getMaterial() const { return material; }
    void setMaterial(const std::string& material) { this->material = material; }

    std::string getColor() const { return color; }
    void setColor(const std::string& color) { this->color = color; }

    void display() const override {
        std::cout << "Меблі: " << name << "\nЦіна: " << price << " грн\nКількість: " << stock
            << "\nМатеріал: " << material << "\nКолір: " << color << "\n";
    }
};

class Electronics : public Product {
private:
    std::string brand;
    int warrantyPeriod;

public:
    Electronics(const std::string& name, double price, int stock, const std::string& brand, int warrantyPeriod)
        : Product(name, price, stock), brand(brand) {
        setWarrantyPeriod(warrantyPeriod);
    }

    std::string getBrand() const { return brand; }
    void setBrand(const std::string& brand) { this->brand = brand; }

    int getWarrantyPeriod() const { return warrantyPeriod; }
    void setWarrantyPeriod(int warrantyPeriod) {
        if (warrantyPeriod < 0)
            throw std::invalid_argument("Гарантійний термін не може бути від'ємним.");
        this->warrantyPeriod = warrantyPeriod;
    }

    void display() const override {
        std::cout << "Електроніка: " << name << "\nЦіна: " << price << " грн\nКількість: " << stock
            << "\nБренд: " << brand << "\nГарантійний термін: " << warrantyPeriod << " місяців\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
     
        Furniture chair("Стілець", 1200.0, 10, "Дерево", "Коричневий");
        Electronics phone("Смартфон", 15000.0, 5, "Samsung", 24);

      
        chair.display();
        std::cout << "-----------------------\n";
        phone.display();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Помилка: " << e.what() << "\n";
    }

    return 0;
}
