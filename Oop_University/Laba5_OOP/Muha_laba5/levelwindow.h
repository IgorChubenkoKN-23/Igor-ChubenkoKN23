#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H

#include <QMainWindow>
#include "fly.h"

class LevelWindow : public QMainWindow {
    Q_OBJECT

public:
    LevelWindow(int level, QWidget *parent = nullptr);
    ~LevelWindow();

protected:
    bool event(QEvent *event) override;

private:
    QVector<Fly*> flies;
    QLabel *trap;
    QLabel *windowLabel;
    int currentLevel;

    void setupLevel(int level);
    bool checkCollision();
};

#endif
