#include "textdevice.h"

TextDevice::TextDevice()
{
    mCount = 0;
}

void TextDevice::run()
{
    exec();
}

void TextDevice::stop()
{
    quit();
}

void TextDevice::write(TextAndNumber tan)
{
    QMutexLocker locker(&mutex);

    qDebug()<< QString("call %1, %2, %3").arg(mCount++).arg(tan.text).arg(tan.number);
}

