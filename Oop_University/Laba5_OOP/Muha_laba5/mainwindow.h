#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(int level = 1, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool event(QEvent *event) override;

private:
    QLabel *fly;
    QLabel *trap;
    QLabel *windowLabel;
    int currentLevel;

    void moveFly();
    bool checkCollision();
    bool checkWindowCollision();
    void moveFlyTowardsWindow();
    void advanceToNextLevel();
    void restartGame();
    void setPositionsForLevel(int level);
};

#endif
