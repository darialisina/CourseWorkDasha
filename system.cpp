#include <QtNetwork/QNetworkReply>
#include "system.h"
#include "new.h"
#include <QXmlStreamReader>
#include <algorithm>
#include <iostream>
#include "mainwindow.h"



void System::getInternetNews()
{
    std::list <QString> urls;
    urls.push_back("https://news.yandex.ru/index.rss");
    urls.push_back("https://lenta.ru/rss/");

    for_each(urls.begin(), urls.end(), [=](QString u){
    request.setUrl(QUrl(u));
    manager -> get(request);

    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply)
    {
        if(reply->error()){
            qDebug() << reply->errorString();
            return;
        }
         QByteArray result = reply->readAll();
         formNews(result);
      });
    });

}

void System::formNews(QByteArray result)
{
    QString xmlTitle;
    QString xmlLink;
    QString xmlDescription;
    std::list<New> *news = new std::list<New>();

    QXmlStreamReader xmlRes(result);
    while (!xmlRes.atEnd() && !xmlRes.hasError())
    {
        QXmlStreamReader::TokenType token = xmlRes.readNext();
        if (token == QXmlStreamReader::StartElement)
        {
            if (xmlRes.name() == "title")
            {
                xmlTitle = xmlRes.readElementText();
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
           New *n = new New(xmlTitle, xmlLink, xmlDescription);
           news->push_back(*n) ;
        }
    }
    emit readyNews(news);
}

System::System(QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager();

    getInternetNews();
}

System::~System() {
    delete manager;
}
