#include "levelwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QRandomGenerator>

LevelWindow::LevelWindow(int level, QWidget *parent)
    : QMainWindow(parent), trap(new QLabel(this)), windowLabel(new QLabel(this)), currentLevel(level) {
    setupLevel(currentLevel);

    QPixmap trapImage("E:/Second_course/ООП/testqt/muha/sik.png");
    trap->setPixmap(trapImage.scaled(100, 100, Qt::KeepAspectRatio));
    trap->setGeometry(150, 150, 100, 100);

    if (currentLevel > 1) {
        windowLabel->setVisible(true);
        QPixmap windowImage("E:/Second_course/ООП/testqt/muha/window.png");
        windowLabel->setPixmap(windowImage.scaled(100, 100, Qt::KeepAspectRatio));
        windowLabel->setGeometry(300, 300, 100, 100);
    } else {
        windowLabel->setVisible(false);
    }
}

LevelWindow::~LevelWindow() {
    qDeleteAll(flies);
}

void LevelWindow::setupLevel(int level) {
    qDeleteAll(flies);
    flies.clear();

    for (int i = 0; i < level; ++i) {
        Fly *fly = new Fly(this, "E:/Second_course/ООП/testqt/muha/fly.png");
        flies.append(fly);
        fly->show();
    }
}

bool LevelWindow::checkCollision() {
    for (Fly *fly : flies) {
        if (fly->geometry().intersects(trap->geometry())) {
            return true;
        }
    }
    return false;
}

bool LevelWindow::event(QEvent *event) {
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        int cursorX = static_cast<int>(mouseEvent->position().x());
        int cursorY = static_cast<int>(mouseEvent->position().y());

        for (Fly *fly : flies) {
            fly->moveAwayFrom(cursorX, cursorY);
        }

        if (checkCollision()) {
            QMessageBox::information(this, "Перемога!", "Ви піймали муху!");
            // Закриває це вікно і створює наступне
            this->close();
            if (currentLevel < 3) { // Перевірка для наступного рівня
                LevelWindow *nextLevel = new LevelWindow(currentLevel + 1);
                nextLevel->show();
            } else {
                QMessageBox::information(nullptr, "Гра пройдена!", "Ви перемогли всі рівні!");
            }
        }
    }
    return QMainWindow::event(event);
}
