#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
private:
    string name;
    string species;
    string age;

public:
    // Методи для встановлення значень
    void setName(string n) { name = n; }
    string getName() const { return name; }

    void setSpecies(string s) { species = s; }
    string getSpecies() { return species; }

    void setAge(string a) { age = a; }
    string getAge() { return age; }
};
#endif