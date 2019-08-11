#ifndef GLOBAL_H
#define GLOBAL_H

#include <QSemaphore>
#include <QChar>
#include <QList>

#include <QDebug>

class global
{
public:
       global();


       bool atEnd;
       int bufferSize;

       //QChar *buffer;
       //QList<QChar> buffer;

       QSemaphore freeSpace;
       QSemaphore availableData;

    //QChar buffer[bufferSize];
    //QSemaphore freeSpace(bufferSize);
    //QSemaphore availableData(zero)

       void addtoBuffer(QChar s, int i);
       void readfromBuffer(int i);
       ~global();

private:
       QChar *buffer;
};

#endif // GLOBAL_H
