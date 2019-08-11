#ifndef IMAGECOLLECTION_H
#define IMAGECOLLECTION_H

#include <QImage>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QStringList>
#include <QList>
#include <QBuffer>
#include <QByteArray>
#include <QImageWriter>
#include <QImageReader>
#include <QString>

#include <QVariant>

class ImageCollection
{
public:
    ImageCollection();

    QImage getImage(int id);
    QList<int> getIds(QStringList tags);
    QStringList getTags();

    void addTag(int id,QString tag);
    void addImage(QImage image,QStringList tags);

private:
    void populateDatabase();
};

#endif // IMAGECOLLECTION_H
