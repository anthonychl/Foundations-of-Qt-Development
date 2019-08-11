#include <QCoreApplication>
#include <QThread>
#include "myobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread ThreadOne;
    MyObject ObjOne;

    QThread ThreadTwo;
    MyObject ObjTwo;

    ObjOne.DoSetup(ThreadOne);
    ObjOne.moveToThread(&ThreadOne);

    ObjTwo.DoSetup(ThreadTwo);
    ObjTwo.moveToThread(&ThreadTwo);

    ThreadOne.start(QThread::HighestPriority);
    ThreadTwo.start();

    ThreadOne.wait();
    ThreadTwo.wait();

    ThreadOne.exit();
    ThreadTwo.exit();

    return a.exec();
}
