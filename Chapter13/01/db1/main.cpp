#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("litedb.db");

    if(!db.open())
    {
        qDebug()<<db.lastError();
        qFatal("fail to connect");
    }
    else
    {
        qDebug()<<"CONNECTED";
        qDebug()<<"QUERYING";
        QSqlQuery qry;
        if( !qry.exec( "SELECT firstname, lastname FROM names WHERE lastname = 'Roe' ORDER BY firstname" ) )
            qDebug() << qry.lastError();

        QSqlRecord rec = qry.record();
        int cols = rec.count();

        QString temp;
        for( int c=0; c<cols; c++ )
        temp += rec.fieldName(c) + ((c<cols-1)?"\t":"");

        qDebug() << temp;

        while( qry.next() )
        {
        temp = "";
        for( int c=0; c<cols; c++ )
        temp += qry.value(c).toString() + ((c<cols-1)?"\t":"");
        qDebug() << temp;
        }

        qDebug()<<"INSERTING";
        qry.prepare("INSERT INTO names (id,firstname,lastname) VALUES (:id,:firstname,:lastname)");
        qry.bindValue(":id",5);
        qry.bindValue(":firstname","Ralph");
        qry.bindValue(":lastname","Roe");

    }

    return a.exec();
}
