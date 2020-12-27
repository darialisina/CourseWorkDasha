#include <QtNetwork/QNetworkReply>
#include "system.h"
#include "new.h"
#include <QXmlStreamReader>
#include <algorithm>
#include <iostream>

QByteArray result;

QByteArray System::getInternetNews()
{
    request.setUrl(QUrl("https://news.yandex.ru/index.rss"));
    manager -> get(request);

    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply)
    {
        if(reply->error()){
            qDebug() << reply->errorString();
            return;
        }
       result = reply->readAll();
      });
    return result;
}

void print(const New n)
{
    qDebug() << n.getTitle().toStdString().c_str();
}

std::list<New> System::formNews()
{
    QString xmlTitel;
    QString xmlLink;
    QString xmlDescription;

    QByteArray res = System::getInternetNews();
    QXmlStreamReader xmlRes(res);
    while (!xmlRes.atEnd() && !xmlRes.hasError())
    {
        QXmlStreamReader::TokenType token = xmlRes.readNext();
        if (token == QXmlStreamReader::StartElement)
        {
            if (xmlRes.name() == "titel")
            {
                xmlTitel = xmlRes.readElementText();
            }
            if (xmlRes.name() == "link")
            {
                xmlLink = xmlRes.readElementText();
            }
            if (xmlRes.name() == "description")
            {
                xmlDescription = xmlRes.readElementText();
            }
        }
        if (token == QXmlStreamReader::EndElement && xmlRes.name() == "item")
        {
           New *n = new New(xmlTitel, xmlLink, xmlDescription);
           news->push_back(*n) ;
        }
    }
    for_each(news->begin(), news->end(),print);
    return *news;
}

System::System(QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();
    news = new std::list<New>;

    formNews();
}

System::~System() {
    delete manager;
    delete news;
}
