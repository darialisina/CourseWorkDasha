#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

#include <list>
#include "new.h"

#ifndef SYSTEM_H
#define SYSTEM_H

class System : public QObject{
Q_OBJECT
private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;

public:
    System(QObject *parent = 0);

    ~System();

   void getInternetNews();
   void formNews(QByteArray result);

signals:
   void readyNews(std::list<New> news);

};

#endif // SYSTEM_H
