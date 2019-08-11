#include "mainwindow.h"
#include <QApplication>

#include <QSemaphore>
#include <QChar>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QMutex>

const int bufferSize = 20;
QChar buffer[ bufferSize ];
QSemaphore freeSpace( bufferSize );
QSemaphore availableData( 0 );
//bool atEnd = false;
QSemaphore atEnd;

class TextProducer: public QThread
{
private:
    QString mText;

public:
    //QSemaphore atEnd;

    TextProducer(QString t)
    {
        mText = t;
        atEnd.release(1);
    }

    void run()
    {
        static int index =0;
        static QMutex indexMutex;

        for( int i=0; i<mText.length(); ++i )
        {
        freeSpace.acquire();

        indexMutex.lock();
        buffer[ index++ % bufferSize ] = mText[ i ];
        indexMutex.unlock();

        if( i == mText.length()-1 )
        atEnd.acquire();
        availableData.release();
        }
    }
};

class TextConsumer: public QThread
{
public:

    void run()
    {
        int i = 0;
        while( atEnd.available() || availableData.available() )
        {
        availableData.acquire();
        qDebug()<< " buffer[ "<<i<<" ] " << buffer[ i ];
        i = (i+1) % bufferSize;
        freeSpace.release();
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();*/
    //return a.exec();

    TextProducer producer1("Lorem ipsum dolor sit amet, ""consectetuer adipiscing elit. ""Praesent tortor." );
    TextProducer producer2("WHAT THE HELL IS THIS THREADING SHIT, DOING THINGS PARALLEL" );
    TextConsumer consumer;

    producer1.start();
    producer2.start();
    consumer.start();


    producer1.wait();
    producer2.wait();
    consumer.wait();

    return 0;
}

