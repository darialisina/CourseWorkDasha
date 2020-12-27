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

    std::list<New>* news;

public:
    System(QObject *parent = 0);

    ~System();

   QByteArray getInternetNews();
   std::list<New> formNews();

};

#endif // SYSTEM_H
