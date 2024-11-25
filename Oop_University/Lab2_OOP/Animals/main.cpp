#include <iostream>
#include <Windows.h>
#include "Animal.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    Animal myAnimal;

    
    cout << "�������� �� �������������:" << endl;
    cout << "��'�: " << myAnimal.getName() << endl;
    cout << "���: " << myAnimal.getSpecies() << endl;
    cout << "³�: " << myAnimal.getAge() << endl;

    myAnimal.setName();
    myAnimal.setSpecies();
    myAnimal.setAge();

 
    cout << "�������� ���� �������� ������������:" << endl;
    cout << "��'�: " << myAnimal.getName() << endl;
    cout << "���: " << myAnimal.getSpecies() << endl;
    cout << "³�: " << myAnimal.getAge() << endl;

   
    Animal anotherAnimal("�����", "ʳ�", 3);

   
    cout << "�������� ���� ��������� � �����������:" << endl;
    cout << "��'�: " << anotherAnimal.getName() << endl;
    cout << "���: " << anotherAnimal.getSpecies() << endl;
    cout << "³�: " << anotherAnimal.getAge() << endl;

   
    Animal copiedAnimal(myAnimal);

   
    cout << "�������� ���� ���������:" << endl;
    cout << "��'�: " << copiedAnimal.getName() << endl;
    cout << "���: " << copiedAnimal.getSpecies() << endl;
    cout << "³�: " << copiedAnimal.getAge() << endl;

    return 0;
}