#include <iostream>
#include <Windows.h>
#include "Animal.h" 

using namespace std;


class Zoo {
private:
    Animal animal; // Композиція - об'єкт класу Animal є частиною Zoo

public:
    Zoo(string name, string species, string age) {
        animal.setName(name);
        animal.setSpecies(species);
        animal.setAge(age);
    }

    void showAnimalInfo() {
        cout << "Тварина в зоопарку: " << animal.getName() << ", "
            << animal.getSpecies() << ", " << animal.getAge() << endl;
    }
};


class PetOwner {
private:
    Animal& pet; // Посилання на об'єкт Animal

public:
    PetOwner(Animal& animal) : pet(animal) {}

    void showPetInfo() {
        cout << "Тварина власника: " << pet.getName() << ", "
            << pet.getSpecies() << ", " << pet.getAge() << endl;
    }
};

// Похідний клас, що використовує наслідування
class Dog : public Animal {
private:
    string breed;

public:
    Dog(string name, string age, string breed) {
        setName(name);
        setSpecies("Собака");
        setAge(age);
        this->breed = breed;
    }

    void showDogInfo() {
        cout << "Собака: " << getName() << ", Порода: " << breed << ", Вік: " << getAge() << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   
    Zoo zooAnimal("Слон", "Ссавець", "25");
    zooAnimal.showAnimalInfo();

   
    Animal myPet;
    myPet.setName("Buddy");
    myPet.setSpecies("Собака");
    myPet.setAge("5");

    PetOwner owner(myPet);
    owner.showPetInfo();

  
    Dog myDog("Rex", "3", "Німецька вівчарка");
    myDog.showDogInfo();

    return 0;
}