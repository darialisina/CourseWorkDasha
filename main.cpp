#include "mainwindow.h"
#include "system.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Новостной агрегатор");
    w.show();
    return a.exec();
}
