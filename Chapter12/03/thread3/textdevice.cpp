#include "textdevice.h"
#include <QDebug>

TextDevice::TextDevice()
{
    count = 0;
}

void TextDevice::write(const QString &text)
{
    QMutexLocker locker(&mutex);
    qDebug()<< QString("Call %1:%2").arg(count++).arg(text);
}
