#include "mainwindow.h"
#include <QApplication>

#include <QMessageBox>
#include "textthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();

    return a.exec();*/

    TextThread foo("FOO"),bar("BAR");
    foo.start();
    bar.start();

    QMessageBox::information(0,"THREADING","Close To Stop");
    foo.stopThread = true;
    bar.stopThread = true;

    foo.wait();
    bar.wait();

    return 0;


}
