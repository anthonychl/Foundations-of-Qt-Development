#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>

using namespace std;
void query1(QSqlQuery *a)
{
    qDebug()<<"QUERYING 1";
    if( !a->exec( "SELECT firstname, lastname FROM names WHERE lastname = 'Roe' ORDER BY firstname" ) )
        qDebug() << a->lastError();
}

void query2(QSqlQuery *a)
{
    qDebug()<<"QUERYING 2";
    if( !a->exec( "SELECT * FROM names ORDER BY id" ) )
        qDebug() << a->lastError();
}

void printing(QSqlQuery *a)
{
    qDebug()<<"PRINTING";
    QSqlRecord rec = a->record();
    int cols = rec.count();

    QString temp;
    for( int c=0; c<cols; c++ )
    temp += rec.fieldName(c) + ((c<cols-1)?"\t":"");

    qDebug() << temp;

    while( a->next() )
    {
    temp = "";
    for( int c=0; c<cols; c++ )
    temp += a->value(c).toString() + ((c<cols-1)?"\t":"");
    qDebug() << temp;
    }

}

void inserting(QSqlQuery *a,int b,char* c, char* d)
{
    qDebug()<<"INSERTING "<<b<<c<<d;
    a->prepare("INSERT INTO names (id,firstname,lastname) VALUES (:id,:firstname,:lastname)");
    a->bindValue(":id",b);
    a->bindValue(":firstname",c);
    a->bindValue(":lastname",d);
    if(!a->exec())
        qDebug()<<"Error inserting";
}

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
        QSqlQuery qry;

        query1(&qry);
        printing(&qry);

        qDebug()<<"insert new data";
        int id;
        char* name = new char(30);
        char* lstname = new char(30);
        qDebug()<<"insert id";
        cin>>id;
        qDebug()<<"insert firstname";
        cin>>name;
        qDebug()<<"insert lastname";
        cin>>lstname;
        inserting(&qry,id,name,lstname);
        query2(&qry);
        printing(&qry);
    }

    return a.exec();
}
