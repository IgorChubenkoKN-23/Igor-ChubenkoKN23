#include "mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QtMath>
#include <QPixmap>

MainWindow::MainWindow(int level, QWidget *parent)
    : QMainWindow(parent), fly(new QLabel(this)), trap(new QLabel(this)), windowLabel(new QLabel(this)), currentLevel(level) {


    resize(800, 600);


    QPixmap flyImage;
    if (currentLevel == 1) {
        flyImage.load("E:/Second_course/ООП/testqt/muha/fly.png");
    } else if (currentLevel == 2) {
        flyImage.load("E:/Second_course/ООП/testqt/muha/fly2.png");
    } else if (currentLevel == 3) {
        flyImage.load("E:/Second_course/ООП/testqt/muha/fly3.png");
    }
    fly->setPixmap(flyImage.scaled(30, 30, Qt::KeepAspectRatio));
    fly->setGeometry(50, 50, 30, 30);


    setPositionsForLevel(currentLevel);


    if (currentLevel > 1) {

        fly->setPixmap(flyImage.scaled(20 + currentLevel * 5, 20 + currentLevel * 5, Qt::KeepAspectRatio));
    }


    windowLabel->show();
}

MainWindow::~MainWindow() {}

bool MainWindow::checkCollision() {
    return fly->geometry().intersects(trap->geometry());
}

bool MainWindow::checkWindowCollision() {
    return fly->geometry().intersects(windowLabel->geometry());
}

void MainWindow::moveFlyTowardsWindow() {

    int flyX = fly->x();
    int flyY = fly->y();
    int windowX = windowLabel->x();
    int windowY = windowLabel->y();

    int dx = windowX - flyX;
    int dy = windowY - flyY;
    double distance = qSqrt(dx * dx + dy * dy);

    if (distance > 5) {
        int moveDistance = 2 + currentLevel;

        int newX = flyX + static_cast<int>(moveDistance * dx / distance);
        int newY = flyY + static_cast<int>(moveDistance * dy / distance);

        fly->move(newX, newY);
    }
}

bool MainWindow::event(QEvent *event) {
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

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
        } else {

            if (currentLevel > 1) {
                moveFlyTowardsWindow();
            }
        }

        if (checkCollision()) {
            QMessageBox::information(this, "Перемога!", "Ви піймали муху!");
            advanceToNextLevel();
        }

        if (checkWindowCollision()) {
            QMessageBox::information(this, "Провал!", "Муха втекла!");
            restartGame();
        }
    }
    return QMainWindow::event(event);
}

void MainWindow::advanceToNextLevel() {

    close();

    MainWindow *nextLevelWindow = new MainWindow(currentLevel + 1);
    nextLevelWindow->show();
}

void MainWindow::restartGame() {

    close();

    MainWindow *newGameWindow = new MainWindow(1);
    newGameWindow->show();
}

void MainWindow::setPositionsForLevel(int level) {
    QPixmap trapImage;
    QPixmap windowImage;

    if (level == 1) {
        trapImage.load("E:/Second_course/ООП/testqt/muha/sik.png");
        windowImage.load("E:/Second_course/ООП/testqt/muha/window.png");

        trap->setPixmap(trapImage.scaled(100, 100, Qt::KeepAspectRatio));
        trap->setGeometry(150, 400, 100, 100);  // Пастка внизу

        windowLabel->setPixmap(windowImage.scaled(100, 100, Qt::KeepAspectRatio));
        windowLabel->setGeometry(600, 400, 100, 100);  // Вікно внизу
    } else if (level == 2) {
        trapImage.load("E:/Second_course/ООП/testqt/muha/trap2.png");
        windowImage.load("E:/Second_course/ООП/testqt/muha/window2.png");

        trap->setPixmap(trapImage.scaled(100, 100, Qt::KeepAspectRatio));
        trap->setGeometry(50, 400, 100, 100);  // Пастка внизу

        windowLabel->setPixmap(windowImage.scaled(100, 100, Qt::KeepAspectRatio));
        windowLabel->setGeometry(600, 400, 100, 100);  // Вікно внизу
    } else if (level == 3) {
        trapImage.load("E:/Second_course/ООП/testqt/muha/trap3.png");
        windowImage.load("E:/Second_course/ООП/testqt/muha/window3.png");

        trap->setPixmap(trapImage.scaled(100, 100, Qt::KeepAspectRatio));
        trap->setGeometry(100, 400, 100, 100);  // Пастка внизу

        windowLabel->setPixmap(windowImage.scaled(100, 100, Qt::KeepAspectRatio));
        windowLabel->setGeometry(600, 400, 100, 100);  // Вікно внизу
    }
}
