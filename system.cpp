#include <QtNetwork/QNetworkReply>
#include "system.h"

void System::getInternetNews()
{
    request.setUrl(QUrl("https://news.yandex.ru/index.rss"));
    manager -> get(request);

    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply)
    {
        if(reply->error()){
            qDebug() << reply->errorString();
            return;
        }
        QString result = reply->readAll();
        qDebug() << result;
    });
}

System::System(QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    news = new std::list<New>;

    getInternetNews();
}

System::~System() {
    delete manager;
    delete news;
}
