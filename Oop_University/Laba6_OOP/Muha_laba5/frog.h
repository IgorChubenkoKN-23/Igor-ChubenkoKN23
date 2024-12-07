#ifndef FROG_H
#define FROG_H

#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QTimer>

class Frog : public QLabel {
    Q_OBJECT

public:
    explicit Frog(QWidget *parent = nullptr);
    void moveFrog();

private:
    QPixmap frogImage;
};

#endif // FROG_H
