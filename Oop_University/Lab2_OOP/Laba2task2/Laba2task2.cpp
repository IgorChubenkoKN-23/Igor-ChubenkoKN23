#include <iostream>
#include <cstring>  
#include <Windows.h>
const int MAX_SIZE = 100;  

class Set {
private:
    int elements[MAX_SIZE];  
    int size;                

public:
    
    Set() : size(0) {
        std::memset(elements, 0, sizeof(elements));  
    }

   
    Set(const int arr[], int n) : size(0) {
        std::memset(elements, 0, sizeof(elements)); 
        for (int i = 0; i < n; ++i) {
            add(arr[i]);
        }
    }

    
    void add(int elem) {
        if (!contains(elem) && size < MAX_SIZE) {
            elements[size++] = elem;
        }
    }

    bool contains(int elem) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == elem) {
                return true;
            }
        }
        return false;
    }


    Set intersection(const Set& other) const {
        Set result;
        for (int i = 0; i < size; ++i) {
            if (other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

   
    Set unionSet(const Set& other) const {
        Set result = *this;
        for (int i = 0; i < other.size; ++i) {
            result.add(other.elements[i]);
        }
        return result;
    }

    // Метод для різниці множин
    Set difference(const Set& other) const {
        Set result;
        for (int i = 0; i < size; ++i) {
            if (!other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

   
    Set symmetricDifference(const Set& other) const {
        Set result;
        for (int i = 0; i < size; ++i) {
            if (!other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        for (int i = 0; i < other.size; ++i) {
            if (!contains(other.elements[i])) {
                result.add(other.elements[i]);
            }
        }
        return result;
    }

    
    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};


Set buildSymmetricDifference(const Set& set1, const Set& set2) {
    return set1.symmetricDifference(set2);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
   
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 4, 5, 6, 7, 8 };

    
    Set set1(arr1, 5);
    Set set2(arr2, 5);


    std::cout << "Множина 1: ";
    set1.print();

    std::cout << "Множина 2: ";
    set2.print();


    Set intersection = set1.intersection(set2);
    std::cout << "Перетин: ";
    intersection.print();


    Set unionSet = set1.unionSet(set2);
    std::cout << "Об'єднання: ";
    unionSet.print();


    Set difference = set1.difference(set2);
    std::cout << "Різниця (Множина 1 \\ Множина 2): ";
    difference.print();

 
    Set symmetricDifference = buildSymmetricDifference(set1, set2);
    std::cout << "Симетрична різниця: ";
    symmetricDifference.print();

    return 0;
}