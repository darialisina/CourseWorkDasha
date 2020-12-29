#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "system.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QDesktopServices>
#include <QUrl>

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

private slots:
   void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

   void on_pushButton_clicked(QLineEdit *lineEdit, QListWidget *lstWdgt);

private:
    Ui::MainWindow *ui;
    System *sys;
    std::list <New>* newNews;
    QNetworkAccessManager *manager;
    QNetworkRequest request;

};
#endif // MAINWINDOW_H
