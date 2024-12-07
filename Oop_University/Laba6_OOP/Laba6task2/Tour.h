#ifndef TOUR_H
#define TOUR_H

#include <string>
#include <iostream>

class Tour {
private:
    std::string name;
    std::string description;
    double price;
    int duration; // Тривалість у днях

public:
    Tour(const std::string& name, const std::string& description, double price, int duration);

    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getDuration() const;

    void print() const;
};

#endif // TOUR_Hц