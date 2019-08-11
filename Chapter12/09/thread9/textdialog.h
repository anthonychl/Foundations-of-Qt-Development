#ifndef TEXTDIALOG_H
#define TEXTDIALOG_H

#include <QDialog>
#include "textandnumber.h"
#include <QAbstractButton>
#include <QMutex>

namespace Ui {
class TextDialog;
}

class TextDialog : public QDialog
{
    Q_OBJECT

public:
   /* explicit TextDialog(QWidget *parent = 0);
    ~TextDialog();*/
    TextDialog();
    ~TextDialog();

public slots:
    void showText(TextAndNumber tan);

private slots:
    void buttonClicked(QAbstractButton*);

private:
    Ui::TextDialog *ui;

    int count;
    QMutex mutex;

};

#endif // TEXTDIALOG_H
