#include "Tour.h"

Tour::Tour(const std::string& name, const std::string& description, double price, int duration)
    : name(name), description(description), price(price), duration(duration) {}

std::string Tour::getName() const { return name; }
std::string Tour::getDescription() const { return description; }
double Tour::getPrice() const { return price; }
int Tour::getDuration() const { return duration; }

void Tour::print() const {
    std::cout << "����� ����: " << name << "\n����: " << description
        << "\nֳ��: " << price << " ���\n���������: " << duration << " ���\n" << std::endl;
}