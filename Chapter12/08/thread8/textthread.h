#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QThread>
#include <QString>

#include "textandnumber.h"

class TextThread: public QThread
{
    Q_OBJECT
public:
    TextThread(const QString& text);
    void run();
    void stop();

signals:
    void writeText(TextAndNumber);

 private:
    QString mText;
    int mCount;
    bool mStop;

};

#endif // TEXTTHREAD_H
