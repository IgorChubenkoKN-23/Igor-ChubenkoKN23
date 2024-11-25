#include "Animal.h"
#include <iostream>

using namespace std;

// Конструктор за замовчуванням
Animal::Animal() : name("Невідоме ім'я"), species("Невідомий вид"), age(0) {
    cout << "Конструктор за замовчуванням викликано" << endl;
}

// Конструктор з параметрами
Animal::Animal(string n, string s, int a) : name(n), species(s), age(a) {
    cout << "Конструктор з параметрами викликано" << endl;
}

// Копіюючий конструктор
Animal::Animal(const Animal& other) : name(other.name), species(other.species), age(other.age) {
    cout << "Копіюючий конструктор викликано" << endl;
}

// Деструктор
Animal::~Animal() {
    cout << "Деструктор викликано для об'єкта з ім'ям: " << name << endl;
}


void Animal::setName() {
    cout << "Введіть ім'я тварини: ";
    cin >> name;
}


void Animal::setSpecies() {
    cout << "Введіть вид тварини: ";
    cin >> species;
}

void Animal::setAge() {
    cout << "Введіть вік тварини: ";
    cin >> age;
}


string Animal::getName() const {
    return name;
}


string Animal::getSpecies() const {
    return species;
}


int Animal::getAge() const {
    return age;
}