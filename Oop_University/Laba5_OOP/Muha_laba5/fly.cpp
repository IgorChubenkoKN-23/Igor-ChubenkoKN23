// fly.cpp
#include "fly.h"
#include <QRandomGenerator>
#include <QtMath>

Fly::Fly(QWidget *parent, const QString &imagePath) : QLabel(parent) {
    QPixmap flyImage(imagePath);
    setPixmap(flyImage.scaled(30, 30, Qt::KeepAspectRatio));
    setGeometry(QRandomGenerator::global()->bounded(parent->width() - 30),
                QRandomGenerator::global()->bounded(parent->height() - 30), 30, 30);
}

void Fly::moveAwayFrom(int cursorX, int cursorY) {
    int flyX = x();
    int flyY = y();
    int dx = cursorX - flyX;
    int dy = cursorY - flyY;
    double distance = qSqrt(dx * dx + dy * dy);

    if (distance < 50) {
        int escapeDistance = 20;
        int newX = flyX - static_cast<int>(escapeDistance * dx / distance);
        int newY = flyY - static_cast<int>(escapeDistance * dy / distance);

        if (newX < 0) newX = escapeDistance;
        if (newY < 0) newY = escapeDistance;
        if (newX + width() > parentWidget()->width()) newX = parentWidget()->width() - width() - escapeDistance;
        if (newY + height() > parentWidget()->height()) newY = parentWidget()->height() - height() - escapeDistance;

        move(newX, newY);
    }
}
