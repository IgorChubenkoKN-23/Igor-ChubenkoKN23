#include <iostream>
#include <Windows.h>
#include "Animal.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    Animal myAnimal;

    
    cout << "Значення за замовчуванням:" << endl;
    cout << "Ім'я: " << myAnimal.getName() << endl;
    cout << "Вид: " << myAnimal.getSpecies() << endl;
    cout << "Вік: " << myAnimal.getAge() << endl;

    myAnimal.setName();
    myAnimal.setSpecies();
    myAnimal.setAge();

 
    cout << "Значення після введення користувачем:" << endl;
    cout << "Ім'я: " << myAnimal.getName() << endl;
    cout << "Вид: " << myAnimal.getSpecies() << endl;
    cout << "Вік: " << myAnimal.getAge() << endl;

   
    Animal anotherAnimal("Барсік", "Кіт", 3);

   
    cout << "Значення після створення з параметрами:" << endl;
    cout << "Ім'я: " << anotherAnimal.getName() << endl;
    cout << "Вид: " << anotherAnimal.getSpecies() << endl;
    cout << "Вік: " << anotherAnimal.getAge() << endl;

   
    Animal copiedAnimal(myAnimal);

   
    cout << "Значення після копіювання:" << endl;
    cout << "Ім'я: " << copiedAnimal.getName() << endl;
    cout << "Вид: " << copiedAnimal.getSpecies() << endl;
    cout << "Вік: " << copiedAnimal.getAge() << endl;

    return 0;
}