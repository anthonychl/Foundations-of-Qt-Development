#include "mainwindow.h"
#include <QApplication>

#include <QSemaphore>
#include <QChar>
#include <QString>
#include <QDebug>
#include <QThread>

const int bufferSize = 20;
QChar buffer[ bufferSize ];
QSemaphore freeSpace( bufferSize );
QSemaphore availableData( 0 );
bool atEnd = false;

class TextProducer: public QThread
{
private:
    QString mText;

public:
    TextProducer(QString t)
    {
        mText = t;
    }

    void run()
    {
        for( int i=0; i<mText.length(); ++i )
        {
        freeSpace.acquire();
        buffer[ i % bufferSize ] = mText[ i ];
        if( i == mText.length()-1 )
        atEnd = true;
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
        while( !atEnd || availableData.available() )
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

    TextProducer producer("Lorem ipsum dolor sit amet, ""consectetuer adipiscing elit. ""Praesent tortor." );
    TextConsumer consumer;

    producer.start();
    consumer.start();


    producer.wait();
    consumer.wait();

    return 0;
}
