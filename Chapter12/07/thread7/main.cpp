#include "mainwindow.h"
#include <QApplication>

#include "textdevice.h"
#include "textthread.h"

#include <QMessageBox>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   /* MainWindow w;
    w.show();


    return a.exec();*/

    TextDevice device;
    TextThread foo("foo"),bar("bar");

    QObject::connect(&foo,SIGNAL(writeText(QString)),&device,SLOT(write(QString)));
    QObject::connect(&bar,SIGNAL(writeText(QString)),&device,SLOT(write(QString)));

    foo.start();
    bar.start();
    device.start();

    QMessageBox::information(0,"Threading","CLOSE ME TO STOP");

    foo.stop();
    bar.stop();
    device.stop();

    foo.wait();
    bar.wait();
    device.wait();

    return 0;
}
