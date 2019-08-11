#include "mainwindow.h"
#include <QApplication>

#include "textandnumber.h"
#include "textdialog.h"
#include "textthread.h"


#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();

    return a.exec();*/

    qRegisterMetaType<TextAndNumber>("TextAndNumber");

    TextDialog device;
    TextThread foo("FOO"),bar("BAR");

    QObject::connect(&foo,SIGNAL(writeText(TextAndNumber)),&device,SLOT(showText(TextAndNumber)));
    QObject::connect(&bar,SIGNAL(writeText(TextAndNumber)),&device,SLOT(showText(TextAndNumber)));

    foo.start();
    bar.start();
    device.exec();

    //QMessageBox::information(0,"THREADING","CLOSE ME TO STOP");

    foo.stop();
    bar.stop();
    //device.close();

    foo.wait();
    bar.wait();
    //device.wait();

    return 0;
}
