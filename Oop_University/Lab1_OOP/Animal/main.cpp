#include <iostream>
#include <Windows.h>
#include "Animal.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ��������� ��'���� ����� "Animal"
    Animal myAnimal;

    // ������������ ������������ ��'����
    myAnimal.setName();
    myAnimal.setSpecies();
    myAnimal.setAge();

    // ������ ������ �����
    cout << "��'�: " << myAnimal.getName() << endl;
    cout << "���: " << myAnimal.getSpecies() << endl;
    cout << "³�: " << myAnimal.getAge() << endl;

    return 0;
}