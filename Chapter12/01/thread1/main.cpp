#include "mainwindow.h"
#include <QApplication>

#include <QMessageBox>
#include "textthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();*/ //esto esta en comentarios xq no se crea ninguna ventana

    TextThread foo("FOO"),bar("BAR");
    foo.start();
    bar.start();

    QMessageBox::information(0,"THREADING","Close To Stop");
    foo.stopThread = true;
    bar.stopThread = true;

    foo.wait();
    bar.wait();

    return 0;
    //return a.exec(); //con esta linea no se cierra el programa hay q usar return0
}
