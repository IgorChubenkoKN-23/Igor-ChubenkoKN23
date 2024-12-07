#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(int level, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool event(QEvent *event) override;

private:
    QLabel *fly;
    QLabel *trap;
    QLabel *windowLabel;
    QLabel *secondFly;
    QLabel *rescuePoint;
    QTimer *flyMoveTimer;
    int currentLevel;
    bool secondFlyCaught;
    bool secondFlyEscaped;
    int flyCaughtCount;
    int attemptsCount;

    bool checkCollision(QLabel *fly);
    bool checkWindowCollision(QLabel *fly);
    void moveFlyTowardsWindow(QLabel *fly);
    void moveFlyTowardsRescue(QLabel *fly);
    void updateFlyCaughtCount();
    void advanceToNextLevel();
    void restartGame();
    void setPositionsForLevel(int level);
    void resetFlyPosition();
};

#endif // MAINWINDOW_H
