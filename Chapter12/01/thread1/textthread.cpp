#include "textthread.h"
#include <QDebug>



TextThread::TextThread( const QString &text): QThread()
{
    mText = text;
    stopThread = false;
}

void TextThread::run()
{
    while(!stopThread)
    {
        qDebug()<< mText;
        sleep(1);
    }
}
