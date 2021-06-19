#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

#include "newfiledialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    newFileDialog newF;
    QFile* newFile;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getFirstName();
    QString getLastName();
    QString getEmailID();

public slots:
    void openNewFileDialog();
    void saveData();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
