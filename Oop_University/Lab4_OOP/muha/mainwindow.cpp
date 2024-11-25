
#include "mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QtMath>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), fly(new QLabel(this)), trap(new QLabel(this))
{

    QPixmap flyImage("E:/Second_course/ООП/testqt/muha/fly.png");
    fly->setPixmap(flyImage.scaled(30, 30, Qt::KeepAspectRatio));
    fly->setGeometry(50, 50, 30, 30);


    QPixmap trapImage("E:/Second_course/ООП/testqt/muha/sik.png");
    trap->setPixmap(trapImage.scaled(30, 30, Qt::KeepAspectRatio));
    trap->setGeometry(150, 150, 100, 100);
}

MainWindow::~MainWindow() {}

bool MainWindow::checkCollision()
{
    return fly->geometry().intersects(trap->geometry());
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        int cursorX = static_cast<int>(mouseEvent->position().x());
        int cursorY = static_cast<int>(mouseEvent->position().y());
        int flyX = fly->x();
        int flyY = fly->y();

        int dx = cursorX - flyX;
        int dy = cursorY - flyY;
        double distance = qSqrt(dx * dx + dy * dy);

        if (distance < 50) {
            int escapeDistance = 20;

            int newX = flyX - static_cast<int>(escapeDistance * dx / distance);
            int newY = flyY - static_cast<int>(escapeDistance * dy / distance);

            if (newX < 0) newX = escapeDistance;
            if (newY < 0) newY = escapeDistance;
            if (newX + fly->width() > width()) newX = width() - fly->width() - escapeDistance;
            if (newY + fly->height() > height()) newY = height() - fly->height() - escapeDistance;

            fly->move(newX, newY);
        }

        if (checkCollision()) {
            QMessageBox::information(this, "Перемогаа!", "Ви піймали муху!");
        }
    }
    return QMainWindow::event(event);
}
