#include "newfiledialog.h"
#include "ui_newfiledialog.h"

#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QFileDialog>

newFileDialog::newFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newFileDialog)
{
    ui->setupUi(this);
}

newFileDialog::~newFileDialog()
{
    delete ui;
}

QString newFileDialog::getFileName()
{
    return fileName;
}

QString newFileDialog::getRecruiterName()
{
    return ui->nameEdit->toPlainText();
}

QString newFileDialog::getLocationName()
{
    return ui->locationEdit->toPlainText();
}

QString newFileDialog::getDate()
{
    int day = ui->dateEdit->date().year();
    int month = ui->dateEdit->date().month();
    int year = ui->dateEdit->date().day();
    return QString::number(year) + "_" + QString::number(month) + "_" + QString::number(day);
}

void newFileDialog::createNewFile()
{
    this->hide();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose Location to Save File:"),
                    "/Desktop", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QString fileName = QFileInfo(dir).absoluteFilePath() + "/" +
                       getLocationName() + "_" + getDate() + ".csv";
    this->fileName = fileName;

    QFile createFile(fileName);
    if ( createFile.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &createFile );
        stream << "Recruiters: " << ", ";
        stream << getRecruiterName() << endl;
        stream << "Location: " << ", ";
        stream << getLocationName() << endl;
        stream << "Date: " << ", ";
        stream << getDate() << endl;

        //create header for further data:
        stream << "First Name" << ", " << "Last Name" << ", " << "Email ID" << endl;
    }
    createFile.close();
}

