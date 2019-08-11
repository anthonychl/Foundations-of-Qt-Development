#include "textthread.h"

TextThread::TextThread(const QString &text)
{
    mText = text;
    mStop = false;
    mCount = 0;
}

void TextThread::stop()
{
    mStop = true;
}

void TextThread::run()
{
    while(!mStop)
    {
        emit writeText(TextAndNumber(mText,mCount++));
        sleep(1);
    }
}
