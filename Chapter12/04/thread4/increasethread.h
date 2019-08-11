#ifndef INCREASETHREAD_H
#define INCREASETHREAD_H

#include <QThread>
#include "textdevice.h"


class IncreaseThread :public QThread
{
public:
    IncreaseThread( TextDevice *device);

    void run();
    bool stopThread;
private:
    TextDevice *mDevice;
};

#endif // INCREASETHREAD_H
