#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QReadWriteLock>
#include <QString>
#include <QDebug>

class TextDevice
{
public:
    TextDevice();

    void increase();
    void write(const QString&);

private:
    QReadWriteLock lock;
    int count;

};

#endif // TEXTDEVICE_H
