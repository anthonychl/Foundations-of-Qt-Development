#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QThread>
#include <QString>

class TextThread : public QThread
{
public:
    TextThread( const QString &text);
    void run();
    bool stopThread;
private:
    QString mText;

};

#endif // TEXTTHREAD_H
