#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>

template<typename T>
class TravelAgency {
private:
    std::vector<std::shared_ptr<T>> tours;

public:
    void addTour(const std::shared_ptr<T>& tour);
    void removeTourByName(const std::string& name);
    void listTours() const;
    void findToursByPrice(double price) const;
};

template<typename T>
void TravelAgency<T>::addTour(const std::shared_ptr<T>& tour) {
    tours.push_back(tour);
}

template<typename T>
void TravelAgency<T>::removeTourByName(const std::string& name) {
    tours.erase(std::remove_if(tours.begin(), tours.end(),
        [&name](const std::shared_ptr<T>& tour) { return tour->getName() == name; }),
        tours.end());
}

template<typename T>
void TravelAgency<T>::listTours() const {
    for (const auto& tour : tours) {
        tour->print();
    }
}

template<typename T>
void TravelAgency<T>::findToursByPrice(double price) const {
    for (const auto& tour : tours) {
        if (tour->getPrice() == price) {
            tour->print();
        }
    }
}

#endif // TRAVELAGENCY_H
