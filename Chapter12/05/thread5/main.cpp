#include "mainwindow.h"
#include <QApplication>

#include "textconsumer.h"
#include "textproducer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();


    return a.exec();*/

    TextProducer producer("Lorem ipsum dolor sit amet,consectetuer adipiscing elit.Praesent tortor." );
    TextConsumer consumer;

    qDebug()<<"Starting";
    producer.start();
    consumer.start();


    producer.wait();
    consumer.wait();
    qDebug()<<"Finished";
    return 0;
}
