#include <QCoreApplication>
#include "ejecutable.h"
#include <QThreadPool>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Ejecutable EJ(1);
    Ejecutable EJ2(2);
    Ejecutable EJ3(3);


    QThreadPool pool;
    pool.start(&EJ,QThread::HighestPriority);
    pool.start(&EJ2,QThread::LowestPriority);

    pool.waitForDone();

    QThreadPool::globalInstance()->start(&EJ3,QThread::LowestPriority);
    QThreadPool::globalInstance()->waitForDone();


    return a.exec();
}
