#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess proceso;

    bool ok = proceso.startDetached("notepad.exe");
    if(ok)
        qDebug()<<"OK1";
    else
        qDebug()<<"ERROR1";

    bool ok2 = proceso.startDetached("F:/AutoEstudio/Qt/Foundations.of.Qt.Development/Chapter12/09/build-thread9-Desktop_Qt_5_1_1_MinGW_32bit-Debug/debug/thread9.exe");
    if(ok2)
        qDebug()<<"OK2";
    else
        qDebug()<<"ERROR2";


    return a.exec();
}
