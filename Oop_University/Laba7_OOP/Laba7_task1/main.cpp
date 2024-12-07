#include "Inventory.h"
#include "Product.h"
#include <iostream>

int main() {
    system("chcp 1251 & cls");
    Inventory inventory;

    
    inventory.addProduct(Product("������", "������", 30.5, 100));
    inventory.addProduct(Product("������", "������ ��������", 28.0, 50));
    inventory.addProduct(Product("���", "������", 15.0, 70));

    std::cout << "\n������ �������� �� �����:\n";
    inventory.displayAllProducts();

   
    inventory.updateProduct("������", 29.0, 60);

    
    inventory.removeProductByName("���");

   
    std::cout << "\n��������� ������ ��������:\n";
    inventory.displayAllProducts();

   
    double totalValue = inventory.calculateTotalValue();
    std::cout << "\n�������� ������� ������: " << totalValue << " ���\n";

    return 0;
}