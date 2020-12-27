#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

#include <list>
#include "new.h"

#ifndef SYSTEM_H
#define SYSTEM_H

class System{

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;

    std::list<New>* news;

public:
    System();

    void getInternetNews();
    void formNews();

};

#endif // SYSTEM_H
