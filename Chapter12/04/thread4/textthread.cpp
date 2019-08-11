#include "textthread.h"

#include <QDebug>



TextThread::TextThread(const QString &text, TextDevice *mD): QThread()
{
    mText = text;
    stopThread = false;

    mDevice = mD; //new TextDevice(mD);
}

void TextThread::run()
{
    while(!stopThread)
    {
        mDevice->write(mText);
        sleep(1);
    }
}
