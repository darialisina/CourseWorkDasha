#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "system.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
   void updatedNews(std::list<New>* news);

private:
    Ui::MainWindow *ui;
    System *sys;
    std::list <New> news;

};
#endif // MAINWINDOW_H
