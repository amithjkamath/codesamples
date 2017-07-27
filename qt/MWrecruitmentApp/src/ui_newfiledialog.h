/********************************************************************************
** Form generated from reading UI file 'newfiledialog.ui'
**
** Created: Fri Sep 25 11:54:56 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILEDIALOG_H
#define UI_NEWFILEDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_newFileDialog
{
public:
    QGroupBox *groupBox;
    QTextBrowser *nameText;
    QDateEdit *dateEdit;
    QTextBrowser *locationText;
    QTextBrowser *dateText;
    QTextEdit *nameEdit;
    QTextEdit *locationEdit;
    QPushButton *OKbutton;
    QPushButton *cancelButton;

    void setupUi(QDialog *newFileDialog)
    {
        QPalette pal = newFileDialog->palette();
        pal.setColor(QPalette::Window, Qt::white);
        newFileDialog->setPalette(pal);

        if (newFileDialog->objectName().isEmpty())
            newFileDialog->setObjectName(QString::fromUtf8("newFileDialog"));
        newFileDialog->resize(700, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newFileDialog->sizePolicy().hasHeightForWidth());
        newFileDialog->setSizePolicy(sizePolicy);
        newFileDialog->setMinimumSize(QSize(700, 500));
        newFileDialog->setMaximumSize(QSize(700, 500));

        nameText = new QTextBrowser(newFileDialog);
        nameText->setObjectName(QString::fromUtf8("nameText"));
        nameText->setGeometry(QRect(100, 60, 500, 40));
        nameText->setFrameShape(QFrame::Panel);
        nameText->setFrameShadow(QFrame::Plain);
        nameText->setLineWidth(0);
        nameEdit = new QTextEdit(newFileDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(100, 110, 500, 40));
        nameEdit->setTabChangesFocus(true);

        locationText = new QTextBrowser(newFileDialog);
        locationText->setObjectName(QString::fromUtf8("locationText"));
        locationText->setGeometry(QRect(100, 160, 500, 40));
        locationText->setFrameShape(QFrame::Panel);
        locationText->setFrameShadow(QFrame::Plain);
        locationText->setLineWidth(0);
        locationEdit = new QTextEdit(newFileDialog);
        locationEdit->setObjectName(QString::fromUtf8("locationEdit"));
        locationEdit->setGeometry(QRect(100, 210, 500, 40));
        locationEdit->setTabChangesFocus(true);

        dateText = new QTextBrowser(newFileDialog);
        dateText->setObjectName(QString::fromUtf8("dateText"));
        dateText->setGeometry(QRect(100, 260, 500, 40));
        dateText->setFrameShape(QFrame::Panel);
        dateText->setFrameShadow(QFrame::Plain);
        dateText->setLineWidth(0);
        dateEdit = new QDateEdit(newFileDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(100, 305, 500, 40));
        dateEdit->setDate(QDate::currentDate());

        OKbutton = new QPushButton(newFileDialog);
        OKbutton->setObjectName(QString::fromUtf8("OKbutton"));
        OKbutton->setGeometry(QRect(200, 360, 125, 40));

        cancelButton = new QPushButton(newFileDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(350, 360, 125, 40));
        QWidget::setTabOrder(nameEdit, locationEdit);
        QWidget::setTabOrder(locationEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, OKbutton);

        retranslateUi(newFileDialog);
        QObject::connect(OKbutton, SIGNAL(clicked()), newFileDialog, SLOT(createNewFile()));
        QObject::connect(cancelButton, SIGNAL(clicked()), newFileDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(newFileDialog);
    } // setupUi

    void retranslateUi(QDialog *newFileDialog)
    {
        newFileDialog->setWindowTitle(QApplication::translate("newFileDialog", "New File", 0, QApplication::UnicodeUTF8));
        nameText->setHtml(QApplication::translate("newFileDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter recruiter names</p></body></html>", 0, QApplication::UnicodeUTF8));
        locationText->setHtml(QApplication::translate("newFileDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter University name</p></body></html>", 0, QApplication::UnicodeUTF8));
        dateText->setHtml(QApplication::translate("newFileDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter date</p></body></html>", 0, QApplication::UnicodeUTF8));
        OKbutton->setText(QApplication::translate("newFileDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("newFileDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newFileDialog: public Ui_newFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILEDIALOG_H
