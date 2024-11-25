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
    // ����������� �� �������������
    Animal();

    // ����������� � �����������
    Animal(string n, string s, int a);

    // �������� �����������
    Animal(const Animal& other);

    // ����������
    ~Animal();

    
    void setName();      
    void setSpecies();   
    void setAge();       

  
    string getName() const;
    string getSpecies() const;
    int getAge() const;
};

#endif