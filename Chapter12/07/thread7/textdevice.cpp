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

void TextDevice::write(const QString &text)
{
    QMutexLocker locker(&mutex);

    qDebug()<< QString("call %1, %2").arg(mCount++).arg(text);
}

