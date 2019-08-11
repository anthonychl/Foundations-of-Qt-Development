#include "global.h"

global::global()
{
           atEnd = false;
           bufferSize = 20;

           freeSpace.release(20);
           availableData.release(1);

           buffer = new QChar[20];
           buffer[0] = 'A';

}

void global::addtoBuffer(QChar s, int i)
{
    buffer[i%bufferSize]=s;
}

void global::readfromBuffer(int i)
{
    qDebug()<<buffer[i];
}

global::~global()
{delete[] buffer;}

