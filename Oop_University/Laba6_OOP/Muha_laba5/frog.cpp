// frog.cpp
#include "frog.h"

Frog::Frog(QWidget *parent) : QLabel(parent) {
    frogImage = QPixmap("E:/Second_course/ООП/testqt/muha/frog.png");
    setPixmap(frogImage.scaled(50, 50, Qt::KeepAspectRatio));
    setGeometry(400, 300, 50, 50);
    show();
}

void Frog::moveFrog() {


    QTimer::singleShot(500, this, [this]() {
        int newX =  750;
        int newY =  550;
        setGeometry(newX, newY, 50, 50);
    });
}
