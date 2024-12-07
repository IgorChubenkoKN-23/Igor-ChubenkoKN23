#ifndef SET_H
#define SET_H

#include <iostream>

const int MAX_SIZE = 100;  

class Set {
private:
    int elements[MAX_SIZE]; 
    int size;                

public:
   
    Set();

   
    Set(const int arr[], int n);

    
    void add(int elem);

    
    bool contains(int elem) const;

   
    Set intersection(const Set& other) const;

    
    Set unionSet(const Set& other) const;

   
    Set difference(const Set& other) const;

   
    Set symmetricDifference(const Set& other) const;

    
    void print() const;

 
    Set operator+(const Set& other) const; 
    Set operator-(const Set& other) const;
    Set operator*(const Set& other) const; 
    Set operator^(const Set& other) const; 
    bool operator==(const Set& other) const; 
    bool operator!=(const Set& other) const; 

   
    friend std::ostream& operator<<(std::ostream& os, const Set& set);
};


Set buildSymmetricDifference(const Set& set1, const Set& set2);

#endif // SET_H