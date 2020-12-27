#include "mainwindow.h"
#include "system.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    System sys;
    sys.getInternetNews();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
