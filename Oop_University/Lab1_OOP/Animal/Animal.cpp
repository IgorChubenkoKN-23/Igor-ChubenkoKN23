#include "Animal.h"
#include <iostream>

using namespace std;

void Animal::setName() {
    cout << "Введіть ім'я тварини: ";
    cin >> name;
}

string Animal::getName() const {
    return name;
}

void Animal::setSpecies() {
    cout << "Введіть вид тварини: ";
    cin >> species;
}

string Animal::getSpecies() {
    return species;
}

void Animal::setAge() {
    cout << "Введіть вік тварини: ";
    cin >> age;
}

string Animal::getAge() {
    return age;
}