#include "mainwindow.h"
#include <QApplication>

#include "imagedialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    ImageDialog dlg;
    dlg.show();

    return a.exec();
}
