#ifndef TEXTANDNUMBER_H
#define TEXTANDNUMBER_H

#include <QString>
#include <QMetaType>

class TextAndNumber
{
public:
    TextAndNumber();
    TextAndNumber(QString, int);

    int number;
    QString text;


};

Q_DECLARE_METATYPE(TextAndNumber)
#endif // TEXTANDNUMBER_H
