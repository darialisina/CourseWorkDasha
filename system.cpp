#include <QtNetwork/QNetworkReply>
#include "system.h"

void System::getInternetNews()
{
    request.setUrl(QUrl("https://news.yandex.ru/index.rss"));
    manager -> get(request);

    QObject::connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply)
    {
        if(reply->error()){
            qDebug() << reply->errorString();
            return;
        }
        QString result = reply->readAll();
        qDebug() << result;
    });
}

System::System(){
    manager = new QNetworkAccessManager();
    getInternetNews();

    news = new std::list<New>;
}
