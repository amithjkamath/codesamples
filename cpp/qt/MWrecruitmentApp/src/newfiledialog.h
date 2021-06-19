#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>

namespace Ui {
class newFileDialog;
}

class newFileDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit newFileDialog(QWidget *parent = 0);
    ~newFileDialog();
    
private:
    Ui::newFileDialog *ui;
    QString fileName;

public slots:
    void createNewFile();

public:
    QString getFileName();
    QString getRecruiterName();
    QString getLocationName();
    QString getDate();

};

#endif // NEWFILEDIALOG_H
