#include "Inventory.h"
#include "Product.h"
#include <iostream>

int main() {
    system("chcp 1251 & cls");
    Inventory inventory;

    
    inventory.addProduct(Product("Яблука", "Фрукти", 30.5, 100));
    inventory.addProduct(Product("Молоко", "Молочні продукти", 28.0, 50));
    inventory.addProduct(Product("Хліб", "Випічка", 15.0, 70));

    std::cout << "\nСписок продуктів на складі:\n";
    inventory.displayAllProducts();

   
    inventory.updateProduct("Молоко", 29.0, 60);

    
    inventory.removeProductByName("Хліб");

   
    std::cout << "\nОновлений список продуктів:\n";
    inventory.displayAllProducts();

   
    double totalValue = inventory.calculateTotalValue();
    std::cout << "\nЗагальна вартість запасів: " << totalValue << " грн\n";

    return 0;
}