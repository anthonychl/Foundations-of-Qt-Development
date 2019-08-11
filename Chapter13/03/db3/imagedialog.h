#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QList>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QString>
#include "imagecollection.h"

namespace Ui {
class ImageDialog;
}

class ImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageDialog(QWidget *parent = 0);
    ~ImageDialog();

private slots:
    void nextClicked();
    void previousClicked();
    void tagsChanged();
    void addImageClicked();
    void addTagClicked();

private:
    Ui::ImageDialog *ui;

    QStringList selectedTags();
    void updateImages();
    void updateTags();
    void updateCurrentImage();
    QList<int> imageIds ;
    int currentImage;

    ImageCollection images;

};

#endif // IMAGEDIALOG_H
