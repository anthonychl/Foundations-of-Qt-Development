#include "imagedialog.h"
#include "ui_imagedialog.h"

ImageDialog::ImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageDialog)
{
    ui->setupUi(this);

    currentImage = -1;

    updateImages();
    updateTags();

    connect(ui->previousButton,SIGNAL(clicked()),this,SLOT(previousClicked()));
    connect(ui->nextButton,SIGNAL(clicked()),this,SLOT(nextClicked()));
    connect(ui->addTagButton,SIGNAL(clicked()),this,SLOT(addTagClicked()));
    connect(ui->addImageButton,SIGNAL(clicked()),this,SLOT(addImageClicked()));
    connect(ui->tagList,SIGNAL(itemSelectionChanged()),this,SLOT(tagsChanged()));

}

void ImageDialog::nextClicked()
{
    currentImage = (currentImage+1)%imageIds.count();
    updateCurrentImage();
}

void ImageDialog::previousClicked()
{
    currentImage --;
    if(currentImage==-1)
        currentImage=imageIds.count()-1;
    updateCurrentImage();
}

void ImageDialog::tagsChanged()
{
    updateImages();
}

void ImageDialog::addTagClicked()
{
    bool ok;
    QString tag= QInputDialog::getText(this,tr("Image Book"),tr("Tag:"),QLineEdit::Normal,QString(),&ok);

    if(ok)
    {
        tag =tag.toLower();
        QRegExp re("[a-z]+");
        if(!re.exactMatch(tag))//if(re.exactMatch(tag)) possible book error
        {
            QMessageBox::warning(this,tr("Image Book"),tr("Error, tags consist of lower case characters a-z"));
            return;
        }
        images.addTag(imageIds[currentImage],tag);
        updateTags();
    }
}

void ImageDialog::addImageClicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),QString(),tr("PNG IMAGES(*.png)"));
    if(!filename.isNull())
    {
        QImage image(filename);
        if(image.isNull())
        {
            QMessageBox::warning(this,tr("Image Book"),tr("Unable to open file %1").arg(filename));
            return;
        }
        images.addImage(image,selectedTags());
        updateImages();
    }


}

QStringList ImageDialog::selectedTags()
{
    QStringList result;
    foreach(QListWidgetItem *item,ui->tagList->selectedItems())
    {
        result<<item->text();
    }
    return result;
}

void ImageDialog::updateTags()
{
    QStringList selection = selectedTags();

    QStringList tags = images.getTags();
    ui->tagList->clear();
    ui->tagList->addItems(tags);

    for (int i = 0; i < ui->tagList->count(); ++i) {
        if(selection.contains(ui->tagList->item(i)->text()))
            ui->tagList->item(i)->setSelected(true);
    }
}

void ImageDialog::updateImages()
{
    int id;
    if(currentImage!=-1)
        id = imageIds[currentImage];
    else
        id =-1;

    imageIds = images.getIds(selectedTags());
    currentImage = imageIds.indexOf(id);

    if(currentImage == -1 && !imageIds.isEmpty())
        currentImage=0;

    ui->imagesLabel->setText(QString::number(imageIds.count()));

    updateCurrentImage();

}

void ImageDialog::updateCurrentImage()
{
    if(currentImage==-1)
    {
        ui->imageLabel->setPixmap(QPixmap());
        ui->imageLabel->setText("No Image");

        ui->addTagButton->setEnabled(false);
        ui->nextButton->setEnabled(false);
        ui->previousButton->setEnabled(false);
    }
    else
    {
        ui->imageLabel->clear();
        ui->imageLabel->setPixmap(QPixmap::fromImage(images.getImage(imageIds[currentImage])));
        ui->addTagButton->setEnabled(true);
        ui->nextButton->setEnabled(true);
        ui->previousButton->setEnabled(true);
    }
}


ImageDialog::~ImageDialog()
{
    delete ui;
}
