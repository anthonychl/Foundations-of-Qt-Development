#ifndef TEXTPRODUCER_H
#define TEXTPRODUCER_H

#include "global.h"
#include <QThread>
#include <QDebug>

class TextProducer : public global,public QThread
{
private:
    QString mText;

public:
    TextProducer(QString t);


    void run();

};

#endif // TEXTPRODUCER_H
