#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QtGui>
// forward class declarations.
 class QAction;
 class QLabel;
 class QMenu;
 class QScrollArea;
 class QScrollBar;
 class QToolBar;
 class QToolButton;


#include "image.h"

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = 0);
    ~ImageViewer();

    void createActions();
    void createMenu();
    void createToolbar();
    void createStatusBar();

private slots:

    void open();
    void saveAs();

    void smoothCB();
    void brightCB();

    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();

private:
    image       im;
    QLabel      *imageLabel;
    QScrollArea *scrollArea;
    double      scaleFactor;
    //toolbar area.
    QToolBar *imToolbar;

    QMenu   *fileMenu;
    QAction *openAct;
    QAction *saveAsAct;
    QAction *exitAct;

    QMenu   *viewMenu;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;

    QMenu   *editMenu;
    QAction *smoothAct;
    QAction *brightAct;

    QMenu   *helpMenu;
    QAction *aboutAct;

    void updateActions();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    //Toolbar buttons
    QToolButton *openButton;

    //Status Bar messages
    QLabel *statusBarNotification;
};

#endif // IMAGEVIEWER_H
