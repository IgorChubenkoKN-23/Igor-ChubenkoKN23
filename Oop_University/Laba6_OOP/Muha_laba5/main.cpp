#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w(1); // Передаємо початковий рівень гри
    w.show();
    return a.exec();
}
