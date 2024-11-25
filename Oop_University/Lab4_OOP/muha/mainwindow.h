#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool event(QEvent *event) override;

private:
    QLabel *fly;
    QLabel *trap;

    void moveFly();
    bool checkCollision();
};

#endif
