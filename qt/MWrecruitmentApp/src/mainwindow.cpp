#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QFile>

#include "newfiledialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getFirstName()
{
    return ui->firstNameBox->toPlainText();
}

QString MainWindow::getLastName()
{
    return ui->lastNameBox->toPlainText();
}

QString MainWindow::getEmailID()
{
    return ui->emailBox->toPlainText();
}

void MainWindow::openNewFileDialog()
{
    newF.show();
}

void MainWindow::saveData()
{
    // open file
    QFile fileToWrite(newF.getFileName());

    //save data
    if (fileToWrite.open(QIODevice::Append)) {
      QTextStream stream(&fileToWrite);
      stream << getFirstName() << ", ";
      stream << getLastName() << ", ";
      stream << getEmailID() << ", " << endl;

      //close file
      fileToWrite.close();
    }

    //clear form
    ui->firstNameBox->clear();
    ui->lastNameBox->clear();
    ui->emailBox->clear();

    //make status bar say thanks!
}
