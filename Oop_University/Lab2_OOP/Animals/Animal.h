#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
private:
    string name;
    string species;
    int age;

public:
    // Конструктор за замовчуванням
    Animal();

    // Конструктор з параметрами
    Animal(string n, string s, int a);

    // Копіюючий конструктор
    Animal(const Animal& other);

    // Деструктор
    ~Animal();

    
    void setName();      
    void setSpecies();   
    void setAge();       

  
    string getName() const;
    string getSpecies() const;
    int getAge() const;
};

#endif