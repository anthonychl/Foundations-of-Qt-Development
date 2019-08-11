#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QThread>
#include <QString>

class TextThread: public QThread
{
    Q_OBJECT
public:
    TextThread(const QString& text);
    void run();
    void stop();

signals:
    void writeText(const QString&);

 private:
    QString mText;
    bool mStop;

};

#endif // TEXTTHREAD_H
