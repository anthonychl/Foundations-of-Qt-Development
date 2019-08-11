#include "increasethread.h"

IncreaseThread::IncreaseThread(TextDevice *device):QThread()
{
    mDevice = device;

    stopThread = false;
}

void IncreaseThread::run()
{
    while(!stopThread)
    {
        msleep(1200);
        mDevice->increase();
    }
}
