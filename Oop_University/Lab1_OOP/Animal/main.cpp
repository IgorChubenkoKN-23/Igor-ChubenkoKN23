#include <iostream>
#include <Windows.h>
#include "Animal.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створення об'єкта класу "Animal"
    Animal myAnimal;

    // Налаштування властивостей об'єкта
    myAnimal.setName();
    myAnimal.setSpecies();
    myAnimal.setAge();

    // Виклик методів класу
    cout << "Ім'я: " << myAnimal.getName() << endl;
    cout << "Вид: " << myAnimal.getSpecies() << endl;
    cout << "Вік: " << myAnimal.getAge() << endl;

    return 0;
}