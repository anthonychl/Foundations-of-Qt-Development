#include "mainwindow.h"
#include <QApplication>

#include "textandnumber.h"
#include "textdevice.h"
#include "textthread.h"

//#include <QMetaType>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();

    return a.exec();*/
    
    qRegisterMetaType<TextAndNumber>("TextAndNumber");

    TextDevice device;
    TextThread foo("FOO"),bar("BAR");

    QObject::connect(&foo,SIGNAL(writeText(TextAndNumber)),&device,SLOT(write(TextAndNumber)));
    QObject::connect(&bar,SIGNAL(writeText(TextAndNumber)),&device,SLOT(write(TextAndNumber)));

    foo.start();
    bar.start();
    device.start();

    QMessageBox::information(0,"THREADING","CLOSE ME TO STOP");

    foo.stop();
    bar.stop();
    device.stop();

    foo.wait();
    bar.wait();
    device.wait();

    return 0;
}
