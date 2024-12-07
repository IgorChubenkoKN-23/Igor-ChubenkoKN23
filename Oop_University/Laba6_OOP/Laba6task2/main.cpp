#include "Tour.h"
#include "TravelAgency.h"
#include <iostream>
#include <memory>

int main() {

    TravelAgency<Tour> agency;
    system("chcp 1251 & cls");
    auto tour1 = std::make_shared<Tour>("������� ���", "³�������� �� �������� ������.", 5000.0, 7);
    auto tour2 = std::make_shared<Tour>("ó���� �������", "����� ������������ ������.", 7500.0, 10);
    auto tour3 = std::make_shared<Tour>("̳��� ��������", "���������� ���������� ���.", 4000.0, 5);

    agency.addTour(tour1);
    agency.addTour(tour2);
    agency.addTour(tour3);

    std::cout << "�� ������� ����:\n";
    agency.listTours();

    std::cout << "���� � ����� 5000 ���:\n";
    agency.findToursByPrice(5000.0);

    std::cout << "��������� ���� '������� ���'...\n";
    agency.removeTourByName("������� ���");

    std::cout << "��������� ������ ����:\n";
    agency.listTours();

    return 0;
}