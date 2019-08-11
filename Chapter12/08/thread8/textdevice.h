#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QThread>
#include <QString>
#include <QMutex>
#include <QDebug>

#include "textandnumber.h"

class TextDevice: public QThread
{
    Q_OBJECT
public:
    TextDevice();

    void run();
    void stop();

public slots:
    void write(TextAndNumber);

private:
    int mCount;
    QMutex mutex;


};

#endif // TEXTDEVICE_H
