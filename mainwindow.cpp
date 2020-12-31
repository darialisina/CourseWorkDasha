#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system.h"
#include <QListWidget>
#include <QtNetwork/QNetworkReply>

void MainWindow::updatedNews(std::list<New>* news)
   {
    newNews = news;

    QListWidget *lstWdgt = ui->listWidget;
    for_each(news->begin(), news->end(), [=](New n)
    {
       QString item ="     " + n.getTitle().toUpper()+"\r\n"+n.getContent();
       lstWdgt->addItem(item);
      });

   }

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();

    for_each(newNews->begin(), newNews->end(), [=](New n){
       QString l1 = (n.getTitle()+" "+n.getContent()).toLower();

       if (l1.contains((ui->lineEdit->text()).toLower())){
           QString item ="     " + n.getTitle().toUpper()+"\r\n"+n.getContent();
           ui->listWidget->addItem(item);
       }

    });
    ui->listWidget->repaint();
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    auto found = find_if(newNews->begin(), newNews->end(), [item](New n) {
            return ("     " + n.getTitle()+"\r\n"+n.getContent()).toLower() == (item->text()).toLower();
        });
            QString link = found->getLink();
            QDesktopServices::openUrl(QUrl(link));

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


