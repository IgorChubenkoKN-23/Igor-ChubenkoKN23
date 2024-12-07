#include "Tour.h"
#include "TravelAgency.h"
#include <iostream>
#include <memory>

int main() {

    TravelAgency<Tour> agency;
    system("chcp 1251 & cls");
    auto tour1 = std::make_shared<Tour>("Пляжний рай", "Відпочинок на сонячних пляжах.", 5000.0, 7);
    auto tour2 = std::make_shared<Tour>("Гірські пригоди", "Похід мальовничими горами.", 7500.0, 10);
    auto tour3 = std::make_shared<Tour>("Міські відкриття", "Дослідження історичних міст.", 4000.0, 5);

    agency.addTour(tour1);
    agency.addTour(tour2);
    agency.addTour(tour3);

    std::cout << "Усі доступні тури:\n";
    agency.listTours();

    std::cout << "Тури з ціною 5000 грн:\n";
    agency.findToursByPrice(5000.0);

    std::cout << "Видалення туру 'Пляжний рай'...\n";
    agency.removeTourByName("Пляжний рай");

    std::cout << "Оновлений список турів:\n";
    agency.listTours();

    return 0;
}