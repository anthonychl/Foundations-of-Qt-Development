#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QThread>
#include <QString>
#include "textdevice.h"

class TextThread : public QThread
{
public:
    TextThread(const QString &text, TextDevice *mD);
    void run();
    bool stopThread;
private:
    QString mText;
    TextDevice *mDevice;
};

#endif // TEXTTHREAD_H
