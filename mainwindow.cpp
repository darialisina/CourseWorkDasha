#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>

void MainWindow::updatedNews(std::list<New>* news)
   {
    QListWidget *lstWdgt = ui->listWidget;
    for_each(news->begin(), news->end(), [=](New n)
    {
//       lstWdgt->addItem(n.getTitle());
       qDebug() << n.getTitle() ;
      });
   }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sys = new System();
    connect(sys, &System::readyNews, this, &MainWindow::updatedNews);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sys;
}






