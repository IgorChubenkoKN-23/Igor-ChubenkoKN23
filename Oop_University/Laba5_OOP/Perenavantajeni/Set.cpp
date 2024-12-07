#include "Set.h"
#include <cstring>  // Для memset

// Конструктор за замовчуванням
Set::Set() : size(0) {
    std::memset(elements, 0, sizeof(elements));  // Ініціалізація масиву нулями
}


Set::Set(const int arr[], int n) : size(0) {
    std::memset(elements, 0, sizeof(elements));  
    for (int i = 0; i < n; ++i) {
        add(arr[i]);
    }
}

void Set::add(int elem) {
    if (!contains(elem) && size < MAX_SIZE) {
        elements[size++] = elem;
    }
}


bool Set::contains(int elem) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == elem) {
            return true;
        }
    }
    return false;
}


Set Set::intersection(const Set& other) const {
    Set result;
    for (int i = 0; i < size; ++i) {
        if (other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    return result;
}


Set Set::unionSet(const Set& other) const {
    Set result = *this;
    for (int i = 0; i < other.size; ++i) {
        result.add(other.elements[i]);
    }
    return result;
}


Set Set::difference(const Set& other) const {
    Set result;
    for (int i = 0; i < size; ++i) {
        if (!other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    return result;
}


Set Set::symmetricDifference(const Set& other) const {
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


void Set::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

// Перевантажені оператори
Set Set::operator+(const Set& other) const {
    return unionSet(other);
}

Set Set::operator-(const Set& other) const {
    return difference(other);
}

Set Set::operator*(const Set& other) const {
    return intersection(other);
}

Set Set::operator^(const Set& other) const {
    return symmetricDifference(other);
}

bool Set::operator==(const Set& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (!other.contains(elements[i])) {
            return false;
        }
    }
    return true;
}

bool Set::operator!=(const Set& other) const {
    return !(*this == other);
}


std::ostream& operator<<(std::ostream& os, const Set& set) {
    for (int i = 0; i < set.size; ++i) {
        os << set.elements[i] << " ";
    }
    return os;
}


Set buildSymmetricDifference(const Set& set1, const Set& set2) {
    return set1.symmetricDifference(set2);
}