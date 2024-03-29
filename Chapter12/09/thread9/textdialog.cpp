#include "textdialog.h"
#include "ui_textdialog.h"

/*
TextDialog::TextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextDialog)
{
    ui->setupUi(this);


}*/

TextDialog::TextDialog()
{
    ui->setupUi(this);

    connect( ui->buttonBox, SIGNAL(clicked(QAbstractButton*)),
    this, SLOT(buttonClicked(QAbstractButton*)) );
    count = 0;
}

void TextDialog::buttonClicked( QAbstractButton *Dbutton )
{
/*if( ui->buttonBox->buttonRole( button ) == QDialogButtonBox::ResetRole )
    ui->listWidget->clear();

if( ui->buttonBox->buttonRole( button ) == QDialogButtonBox::Close )
    ui->listWidget->close();*/

   if( ui->buttonBox->buttonRole(Dbutton) == QDialogButtonBox::Reset )
        ui->listWidget->clear();



}

void TextDialog::showText( TextAndNumber tan )
{
QMutexLocker locker( &mutex );
ui->listWidget->addItem( QString( "Call %1 (%3): %2" )
.arg( count++ )
.arg( tan.text )
.arg( tan.number ) );
}

TextDialog::~TextDialog()
{
    delete ui;
}
