// fly.h
#ifndef FLY_H
#define FLY_H

#include <QLabel>

class Fly : public QLabel {
public:
    Fly(QWidget *parent, const QString &imagePath);
    void moveAwayFrom(int cursorX, int cursorY);
};

#endif
