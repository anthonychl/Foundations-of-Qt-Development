/********************************************************************************
** Form generated from reading UI file 'imagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDIALOG_H
#define UI_IMAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ImageDialog
{
public:
    QListWidget *tagList;
    QLabel *imagesLabel;
    QLabel *imageLabel;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *addTagButton;
    QPushButton *addImageButton;

    void setupUi(QDialog *ImageDialog)
    {
        if (ImageDialog->objectName().isEmpty())
            ImageDialog->setObjectName(QStringLiteral("ImageDialog"));
        ImageDialog->resize(677, 480);
        tagList = new QListWidget(ImageDialog);
        tagList->setObjectName(QStringLiteral("tagList"));
        tagList->setGeometry(QRect(535, 10, 131, 441));
        tagList->setSelectionMode(QAbstractItemView::MultiSelection);
        imagesLabel = new QLabel(ImageDialog);
        imagesLabel->setObjectName(QStringLiteral("imagesLabel"));
        imagesLabel->setGeometry(QRect(540, 450, 131, 20));
        imageLabel = new QLabel(ImageDialog);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(15, 12, 501, 411));
        previousButton = new QPushButton(ImageDialog);
        previousButton->setObjectName(QStringLiteral("previousButton"));
        previousButton->setGeometry(QRect(10, 440, 75, 23));
        nextButton = new QPushButton(ImageDialog);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(100, 440, 75, 23));
        addTagButton = new QPushButton(ImageDialog);
        addTagButton->setObjectName(QStringLiteral("addTagButton"));
        addTagButton->setGeometry(QRect(310, 440, 75, 23));
        addImageButton = new QPushButton(ImageDialog);
        addImageButton->setObjectName(QStringLiteral("addImageButton"));
        addImageButton->setGeometry(QRect(400, 440, 75, 23));

        retranslateUi(ImageDialog);

        QMetaObject::connectSlotsByName(ImageDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageDialog)
    {
        ImageDialog->setWindowTitle(QApplication::translate("ImageDialog", "Dialog", 0));
        imagesLabel->setText(QApplication::translate("ImageDialog", "Images:", 0));
        imageLabel->setText(QApplication::translate("ImageDialog", "No Image", 0));
        previousButton->setText(QApplication::translate("ImageDialog", "Prev", 0));
        nextButton->setText(QApplication::translate("ImageDialog", "Next", 0));
        addTagButton->setText(QApplication::translate("ImageDialog", "AddTag", 0));
        addImageButton->setText(QApplication::translate("ImageDialog", "AddImage", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageDialog: public Ui_ImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDIALOG_H
