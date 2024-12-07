#include <iostream>
#include <Windows.h>
#include "Set.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 4, 5, 6, 7, 8 };

    
    Set set1(arr1, 5);
    Set set2(arr2, 5);

   
    std::cout << "Множина 1: " << set1 << std::endl;
    std::cout << "Множина 2: " << set2 << std::endl;

   
    Set intersection = set1 * set2;
    std::cout << "Перетин: " << intersection << std::endl;

  
    Set unionSet = set1 + set2;
    std::cout << "Об'єднання: " << unionSet << std::endl;

    
    Set difference = set1 - set2;
    std::cout << "Різниця (Множина 1 \\ Множина 2): " << difference << std::endl;

   
    Set symmetricDifference = set1 ^ set2;
    std::cout << "Симетрична різниця: " << symmetricDifference << std::endl;

   
    std::cout << "set1 == set2: " << (set1 == set2 ? "true" : "false") << std::endl;
    std::cout << "set1 != set2: " << (set1 != set2 ? "true" : "false") << std::endl;

    return 0;
}