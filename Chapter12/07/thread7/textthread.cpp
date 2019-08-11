#include "textthread.h"

TextThread::TextThread(const QString &text)
{
    mText = text;
    mStop = false;
}

void TextThread::stop()
{
    mStop = true;
}

void TextThread::run()
{
    while(!mStop)
    {
        emit writeText(mText);
        sleep(1);
    }
}
