#include "mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QtMath>
#include <QPixmap>
#include <QPalette>
#include <QTimer>
#include <QPushButton>
#include <cstdlib>

MainWindow::MainWindow(int level, QWidget *parent)
    : QMainWindow(parent), fly(new QLabel(this)), trap(new QLabel(this)), windowLabel(new QLabel(this)),
    secondFly(nullptr), currentLevel(level), secondFlyCaught(false), secondFlyEscaped(false), flyCaughtCount(0), attemptsCount(0) {

    resize(800, 600);

    QPushButton *nextLevelButton = new QPushButton("Перейти на наступний рівень", this);
    nextLevelButton->setGeometry(width() - 200, 10, 180, 40);
    connect(nextLevelButton, &QPushButton::clicked, this, &MainWindow::advanceToNextLevel);


    flyMoveTimer = new QTimer(this);
    connect(flyMoveTimer, &QTimer::timeout, [this](){ moveFlyTowardsWindow(fly); });
    flyMoveTimer->start(30);


    QPixmap backgroundImage;
    if (currentLevel == 1) {
        backgroundImage.load("E:/Second_course/ООП/testqt/muha/background1.png");
    } else if (currentLevel == 2) {
        backgroundImage.load("E:/Second_course/ООП/testqt/muha/background2.png");
    } else if (currentLevel == 3) {
        backgroundImage.load("E:/Second_course/ООП/testqt/muha/background3.png");
    } else if (currentLevel == 4) {
        backgroundImage.load("E:/Second_course/ООП/testqt/muha/background4.png");
    }


    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage.scaled(size(), Qt::IgnoreAspectRatio));
    setPalette(palette);

    QPixmap flyImage;
    if (currentLevel == 1) {
        flyImage.load("E:/Second_course/ООП/testqt/muha/fly.png");
    } else if (currentLevel == 2) {
        flyImage.load("E:/Second_course/ООП/testqt/muha/fly2.png");
    } else if (currentLevel == 3) {
        flyImage.load("E:/Second_course/ООП/testqt/muha/fly3.png");
    } else if (currentLevel == 4){
        flyImage.load("E:/Second_course/ООП/testqt/muha/fly3.png");
    }
    fly->setPixmap(flyImage.scaled(30, 30, Qt::KeepAspectRatio));
    fly->setGeometry(700, 50, 30, 30);
    fly->show();

    setPositionsForLevel(currentLevel);

    if (currentLevel > 1) {
        fly->setPixmap(flyImage.scaled(20 + currentLevel * 5, 20 + currentLevel * 5, Qt::KeepAspectRatio));
    }

    windowLabel->show();
}

MainWindow::~MainWindow() {}

bool MainWindow::checkCollision(QLabel *fly) {
    return fly->geometry().intersects(trap->geometry());
}

bool MainWindow::checkWindowCollision(QLabel *fly) {
    return fly->geometry().intersects(windowLabel->geometry());
}

void MainWindow::moveFlyTowardsWindow(QLabel *fly) {
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
        }

        if (currentLevel < 4) {
            if (checkCollision(fly) || (currentLevel == 2 && checkWindowCollision(fly))) {
                attemptsCount++;
                QMessageBox::information(this, "Муха потрапила в пастку!", QString("Спроб: %1").arg(attemptsCount));
                resetFlyPosition();
                if (attemptsCount == 5) {
                    advanceToNextLevel();
                }
            }
        }

        if (checkWindowCollision(fly)) {
            QMessageBox::information(this, "Провал!", "Муха втекла!");
            restartGame();
        }


        if (currentLevel == 2 && secondFly) {
            int secondFlyX = secondFly->x();
            int secondFlyY = secondFly->y();

            int dx2 = cursorX - secondFlyX;
            int dy2 = cursorY - secondFlyY;
            double distance2 = qSqrt(dx2 * dx2 + dy2 * dy2);

            if (distance2 < 50) {
                int escapeDistance = 20;

                int newX = secondFlyX - static_cast<int>(escapeDistance * dx2 / distance2);
                int newY = secondFlyY - static_cast<int>(escapeDistance * dy2 / distance2);

                if (newX < 0) newX = escapeDistance;
                if (newY < 0) newY = escapeDistance;
                if (newX + secondFly->width() > width()) newX = width() - secondFly->width() - escapeDistance;
                if (newY + secondFly->height() > height()) newY = height() - secondFly->height() - escapeDistance;

                secondFly->move(newX, newY);
            }

            if (checkCollision(secondFly) || checkWindowCollision(secondFly)) {
                attemptsCount++;
                QMessageBox::information(this, "Муха потрапила в пастку!", QString("Спроб: %1").arg(attemptsCount));
                resetFlyPosition();
                if (attemptsCount == 5) {
                    advanceToNextLevel();
                }
            }
        }
    }
    return QMainWindow::event(event);
}

void MainWindow::resetFlyPosition() {
    fly->move(700, 50);
    if (secondFly) {
        secondFly->move(100, 100);
    }
}

void MainWindow::advanceToNextLevel() {
    if (currentLevel < 4) {
        currentLevel++;
        attemptsCount = 0;
        close();
        MainWindow *nextLevelWindow = new MainWindow(currentLevel);
        nextLevelWindow->show();
    } else {
        QMessageBox::information(this, "Перемога!", "Ви пройшли всі рівні!");
        restartGame();
    }
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
        trap->setGeometry(150, 400, 100, 100);
        trap->show();

        windowLabel->setPixmap(windowImage.scaled(100, 100, Qt::KeepAspectRatio));
        windowLabel->setGeometry(150, 225, 150, 100);
        windowLabel->show();
    } else if (level == 2) {
        trapImage.load("E:/Second_course/ООП/testqt/muha/trap2.png");
        windowImage.load("E:/Second_course/ООП/testqt/muha/window2.png");

        trap->setPixmap(trapImage.scaled(100, 100, Qt::KeepAspectRatio));
        trap->setGeometry(50, 400, 100, 100);
        trap->show();

        windowLabel->setPixmap(windowImage.scaled(100, 100, Qt::KeepAspectRatio));
        windowLabel->setGeometry(600, 400, 100, 100);
        windowLabel->show();

        secondFly = new QLabel(this);
        QPixmap secondFlyImage;
        secondFlyImage.load("E:/Second_course/ООП/testqt/muha/fly.png");
        secondFly->setPixmap(secondFlyImage.scaled(30, 30, Qt::KeepAspectRatio));
        secondFly->setGeometry(100, 100, 30, 30);
        secondFly->show();


        QTimer *secondFlyMoveTimer = new QTimer(this);
        connect(secondFlyMoveTimer, &QTimer::timeout, [this](){ moveFlyTowardsWindow(secondFly); });
        secondFlyMoveTimer->start(30);
    } else if (level == 3) {

        trapImage.load("E:/Second_course/ООП/testqt/muha/trap3.png");
        windowImage.load("E:/Second_course/ООП/testqt/muha/window3.png");


        trap->setPixmap(trapImage.scaled(100, 100, Qt::KeepAspectRatio));
        trap->setGeometry(50, 400, 100, 100);
        trap->show();


        windowLabel->setPixmap(windowImage.scaled(100, 100, Qt::KeepAspectRatio));
        windowLabel->setGeometry(600, 400, 100, 100);
        windowLabel->show();
    } else if (level == 4) {

        QLabel *frog = new QLabel(this);
        QPixmap frogImage("E:/Second_course/ООП/testqt/muha/frog.png");
        frog->setPixmap(frogImage.scaled(70, 70, Qt::KeepAspectRatio));
        frog->setGeometry(350, 250, 70, 70);
        frog->show();


        QTimer *frogTimer = new QTimer(this);
        connect(frogTimer, &QTimer::timeout, [this, frog]() {

            int frogX = frog->x();
            int frogY = frog->y();
            int flyX = fly->x();
            int flyY = fly->y();

            int dx = flyX - frogX;
            int dy = flyY - frogY;
            double distance = qSqrt(dx * dx + dy * dy);

            if (distance > 50) {
                int moveDistance = 25;

                int newFrogX = frogX + static_cast<int>(moveDistance * dx / distance);
                int newFrogY = frogY + static_cast<int>(moveDistance * dy / distance);

                frog->move(newFrogX, newFrogY);
            }
        });
        frogTimer->start(200);


        QTimer *flyTimer = new QTimer(this);
        connect(flyTimer, &QTimer::timeout, [this, frog, flyTimer]() {

            fly->move(fly->x() - 1, fly->y());


            if (fly->geometry().intersects(frog->geometry())) {
                flyTimer->stop();
                QMessageBox::information(this, "Поразка", "Жаба з'їла муху!");
                restartGame();
            }


            if (fly->x() < 50) {
                flyTimer->stop();
                QMessageBox::information(this, "Перемога", "Ви врятувались!Гру закінчено");
                restartGame();
            }
        });
        flyTimer->start(50);
    }
}
