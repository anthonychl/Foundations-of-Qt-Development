#ifndef TEXTCONSUMER_H
#define TEXTCONSUMER_H

#include "global.h"
#include <QThread>
#include <QDebug>

class TextConsumer : public global,public QThread
{
public:
   // TextConsumer();
    void run();

};

#endif // TEXTCONSUMER_H
