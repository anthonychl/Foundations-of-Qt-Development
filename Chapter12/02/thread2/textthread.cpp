#include "textthread.h"
#include <QDebug>
//tiene cambios respecto al ej thread1 en run() y se agrega QMutex
#include <QMutex>

QMutex mutex;

TextThread::TextThread( const QString &text): QThread()
{
    mText = text;
    stopThread = false;
}

void TextThread::run()
{
    while(!stopThread)
    {
        mutex.lock();
        if(stopThread)
        {
            mutex.unlock();
            return;
        }
        qDebug()<< mText;
        sleep(1);
        mutex.unlock();
    }
}
