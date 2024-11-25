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
    void setName();
    string getName() const;
    void setSpecies();
    string getSpecies();
    void setAge();
    string getAge();
};

#endif