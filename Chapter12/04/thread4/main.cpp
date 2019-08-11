#include "mainwindow.h"
#include <QApplication>

#include "textdevice.h"
#include "increasethread.h"
#include "textthread.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();

    return a.exec();*/

    TextDevice device;
    IncreaseThread inc( &device);
    TextThread foo( "foo",&device),boo("boo",&device);

    foo.start();
    boo.start();
    inc.start();

    QMessageBox::information(0,"running threads","Close to STOP");
    foo.stopThread = true;
    boo.stopThread = true;

    foo.wait();
    boo.wait();
    inc.wait();

    return 0;
}
