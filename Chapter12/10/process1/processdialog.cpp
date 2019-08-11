#include "processdialog.h"
#include "ui_processdialog.h"

ProcessDialog::ProcessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProcessDialog)
{
    ui->setupUi(this);
    runUic();
}

ProcessDialog::~ProcessDialog()
{
    delete ui;
}

void ProcessDialog::runUic()
{
    ui->uicButton->setEnabled(false);
    ui->textEdit->setText("...'''...");

    if (process)
        delete process;

    process=new QProcess(this);

    connect(process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(handleError(QProcess::ProcessError)));
    connect(process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(handleFinish(int,QProcess::ExitStatus)));
    connect(process,SIGNAL(readyReadStandardError()),this,SLOT(handleReadStandardError()));
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(handleReadStandardOutput()));
    connect(process,SIGNAL(started()),this,SLOT(handleStarted()));
    connect(process,SIGNAL(stateChanged(QProcess::ProcessState)),this,SLOT(handleStateChange(QProcess::ProcessState)));

    QStringList arguments;
    arguments <<"-tr"<<"MYTR"<<"processdialog.ui";
    process->start("uic",arguments);

}

void ProcessDialog::handleError(QProcess::ProcessError error)
{
    ui->textEdit->append(QString("ERROR: %1").arg(error));
    ui->plainTextEdit->appendPlainText(QString("ERROR: %1").arg(error));
}

void ProcessDialog::handleFinish(int code, QProcess::ExitStatus status)
{
    QString statusText;

    switch(status)
    {
        case QProcess::NormalExit:
             statusText= "Normal Exit";
             break;
        case QProcess::CrashExit:
             statusText= "Crash Exit";
             break;
    }

    ui->textEdit->append(QString("<p><b>%1 (%2)</b></p>").arg(statusText).arg(code));
    ui->plainTextEdit->appendPlainText(QString("<p><b>%1 (%2)</b></p>").arg(statusText).arg(code));
}

void ProcessDialog::handleReadStandardError()
{
    ui->textEdit->append(process->readAllStandardError());
    ui->plainTextEdit->appendPlainText(process->readAllStandardError());
}

void ProcessDialog::handleReadStandardOutput()
{
    ui->textEdit->append(process->readAllStandardOutput());
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void ProcessDialog::handleStarted()
{
    ui->textEdit->append("PROCESS STARTED");
    ui->plainTextEdit->appendPlainText("PROCESS STARTED");
}

void ProcessDialog::handleStateChange(QProcess::ProcessState presentState)
{
    ui->textEdit->append(QString("STATE: %1").arg(presentState));
    ui->plainTextEdit->appendPlainText(QString("STATE: %1").arg(presentState));
}
