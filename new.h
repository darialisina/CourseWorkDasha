#include <QString>

#ifndef NEW_H
#define NEW_H

class New{
private:
    QString titel;
    QString link;
    QString content;
public:
    New(): titel(" "), link(" "), content(" "){};
    New(QString titel, QString link, QString content):titel(titel), link(link), content(content){};

    QString getTitle() const {return titel;}
    QString getLink() const {return link;}
    QString getContent() const {return content;}

};
#endif // NEW_H
