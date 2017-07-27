/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Sep 25 11:30:41 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include <QtGui/QPalette>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *doneButton;
    QTextBrowser *lastName;
    QTextEdit *emailBox;
    QTextEdit *firstNameBox;
    QTextEdit *lastNameBox;
    QTextBrowser *emailText;
    QTextBrowser *firstName;
    QLabel *label;
    QTextBrowser *headerText;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {

        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 800);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setMaximumSize(QSize(800, 800));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        // Make background white by force
        QPalette pal = MainWindow->palette();
        pal.setColor(QPalette::Window, Qt::white);
        MainWindow->setPalette(pal);

        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 200, 600, 400));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        groupBox->setFlat(true);

        headerText = new QTextBrowser(centralWidget);
        headerText->setObjectName(QString::fromUtf8("headerText"));
        headerText->setGeometry(QRect(150, 30, 500, 40));
        headerText->setFrameShape(QFrame::Panel);
        headerText->setFrameShadow(QFrame::Plain);
        headerText->setLineWidth(0);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 75, 500, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/images/MathWorksLogo.jpg")));
        label->setScaledContents(true);

        firstName = new QTextBrowser(groupBox);
        firstName->setObjectName(QString::fromUtf8("firstName"));
        firstName->setGeometry(QRect(50, 20, 500, 40));
        firstName->setFrameShape(QFrame::Panel);
        firstName->setFrameShadow(QFrame::Plain);
        firstName->setLineWidth(0);
        firstNameBox = new QTextEdit(groupBox);
        firstNameBox->setObjectName(QString::fromUtf8("firstNameBox"));
        firstNameBox->setGeometry(QRect(50, 65, 500, 40));
        firstNameBox->setTabChangesFocus(true);
        firstNameBox->setCursorWidth(1);


        lastName = new QTextBrowser(groupBox);
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastName->setGeometry(QRect(50, 115, 500, 40));
        lastName->setFrameShape(QFrame::Panel);
        lastName->setFrameShadow(QFrame::Plain);
        lastName->setLineWidth(0);
        lastNameBox = new QTextEdit(groupBox);
        lastNameBox->setObjectName(QString::fromUtf8("lastNameBox"));
        lastNameBox->setGeometry(QRect(50, 160, 500, 40));
        lastNameBox->setTabChangesFocus(true);
        lastNameBox->setAcceptRichText(true);
        lastNameBox->setCursorWidth(1);

        emailText = new QTextBrowser(groupBox);
        emailText->setObjectName(QString::fromUtf8("emailText"));
        emailText->setGeometry(QRect(50, 210, 500, 40));
        emailText->setFrameShape(QFrame::Panel);
        emailText->setFrameShadow(QFrame::Plain);
        emailText->setLineWidth(0);
        emailBox = new QTextEdit(groupBox);
        emailBox->setObjectName(QString::fromUtf8("emailBox"));
        emailBox->setGeometry(QRect(50, 255, 500, 40));
        emailBox->setTabChangesFocus(true);
        emailBox->setCursorWidth(1);

        doneButton = new QPushButton(groupBox);
        doneButton->setObjectName(QString::fromUtf8("pushButton"));
        doneButton->setGeometry(QRect(260, 310, 80, 30));

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 36));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));

        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        QWidget::setTabOrder(firstNameBox, lastNameBox);
        QWidget::setTabOrder(lastNameBox, emailBox);
        QWidget::setTabOrder(emailBox,doneButton);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionNew, SIGNAL(triggered()), MainWindow, SLOT(openNewFileDialog()));
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(doneButton, SIGNAL(clicked()), MainWindow, SLOT(saveData()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MWrecruitingApp", 0, QApplication::UnicodeUTF8));

        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));

        doneButton->setText(QApplication::translate("MainWindow", "Done", 0, QApplication::UnicodeUTF8));

        lastName->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.Helvetica Neue DeskInterface';\">Last Name</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        emailText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.Helvetica Neue DeskInterface';\">Email Address</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        firstName->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.Helvetica Neue DeskInterface';\">First Name</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        headerText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.Helvetica Neue DeskInterface';\">Thanks for stopping by!</span></p></body></html>", 0, QApplication::UnicodeUTF8));

        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
