#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QMutex>
#include <QString>
class TextDevice
{
public:
    TextDevice();
    void write(const QString&);
private:
    QMutex mutex;
    int count;
};

#endif // TEXTDEVICE_H
