#include "imageviewer.h"
#include <QtGui>
#include <QtAlgorithms>

#include "imagesmoother.h"
#include "imagebrightener.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QMainWindow(parent)
{
    // QLabel is used for displaying text or an image.
    // No user interaction functionality is provided.
    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Dark);
    imageLabel->setScaledContents(true);

    // QScrollArea provides a scrolling view around another widget.
    // If the child widget exceeds the size of the frame, QScrollArea
    // automatically provides scroll bars.
    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);

    createActions();
    createMenu();
    createToolbar();
    createStatusBar();

    setWindowTitle(tr("Image Processing App"));
    // This is the initial size of the window.
    resize(500, 500);
}

ImageViewer::~ImageViewer()
{
}

void ImageViewer::createActions()
 {
     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcut(tr("Ctrl+O"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     saveAsAct = new QAction(tr("&Save As..."), this);
     saveAsAct->setShortcut(tr("Ctrl+S"));
     saveAsAct->setEnabled(false);
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     exitAct = new QAction(tr("&Exit"), this);
     exitAct->setShortcut(tr("Ctrl+Q"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     zoomInAct = new QAction(tr("Zoom &In (25%)"), this);
     zoomInAct->setShortcut(tr("Ctrl++"));
     zoomInAct->setEnabled(false);
     connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

     zoomOutAct = new QAction(tr("Zoom &Out (25%)"), this);
     zoomOutAct->setShortcut(tr("Ctrl+-"));
     zoomOutAct->setEnabled(false);
     connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));

     normalSizeAct = new QAction(tr("&Normal Size"), this);
     normalSizeAct->setShortcut(tr("Ctrl+S"));
     normalSizeAct->setEnabled(false);
     connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(normalSize()));

     fitToWindowAct = new QAction(tr("&Fit to Window"), this);
     fitToWindowAct->setEnabled(false);
     fitToWindowAct->setCheckable(true);
     fitToWindowAct->setShortcut(tr("Ctrl+F"));
     connect(fitToWindowAct, SIGNAL(triggered()), this, SLOT(fitToWindow()));

     smoothAct = new QAction(tr("&Smooth Image"), this);
     smoothAct->setEnabled(false);
     smoothAct->setShortcut(tr("Ctrl+1+S"));
     connect(smoothAct, SIGNAL(triggered()), this, SLOT(smoothCB()));

     brightAct = new QAction(tr("&Brighten Image"), this);
     brightAct->setEnabled(false);
     brightAct->setShortcut(tr("Ctrl+1+B"));
     connect(brightAct, SIGNAL(triggered()), this, SLOT(brightCB()));

     aboutAct = new QAction(tr("&About"), this);
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
 }

void ImageViewer::createMenu()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    viewMenu = new QMenu(tr("&View"), this);
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);
    viewMenu->addAction(normalSizeAct);
    viewMenu->addSeparator();
    viewMenu->addAction(fitToWindowAct);

    editMenu = new QMenu(tr("&Edit"), this);
    editMenu->addAction(smoothAct);
    editMenu->addAction(brightAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(viewMenu);
    menuBar()->addMenu(editMenu);
    menuBar()->addMenu(helpMenu);
}

void ImageViewer::createToolbar()
{
    imToolbar = new QToolBar;
    imToolbar->setGeometry(0,0,200,20);

    imToolbar->addAction(openAct);
    imToolbar->addAction(saveAsAct);
    imToolbar->addAction(zoomInAct);
    imToolbar->addAction(zoomOutAct);

    //don't allow moving the toolbar to other corners of the window.
    imToolbar->setMovable(0);
    imToolbar->setFloatable(0);
    addToolBar(Qt::TopToolBarArea, imToolbar);
}

void ImageViewer::createStatusBar()
{
    statusBarNotification = new QLabel;
    statusBarNotification->setAlignment(Qt::AlignHCenter);
    statusBarNotification->setMinimumSize(statusBarNotification->sizeHint());
    statusBarNotification->setText("Ready...");

    statusBar()->addWidget(statusBarNotification);
}

void ImageViewer::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                        tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        im.fromFile(fileName);
        if (im.isEmpty()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }

        imageLabel->setPixmap(QPixmap::fromImage(im.toQImage()));
        imageLabel->resize(imageLabel->pixmap()->size());

        QSize imSize = im.getSize();
        // fix this
        resize(imSize.width() + 4, imSize.height() + 80);
        setMaximumSize(imSize.width() + 4, imSize.height() + 80);
        imageLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        saveAsAct->setEnabled(true);
        // enable zoom actions.
        scaleFactor = 1.0;
        fitToWindowAct->setEnabled(true);
        updateActions();

        if (fitToWindowAct->isChecked())
        {
            fitToWindow();
        }
        else
        {
            imageLabel->adjustSize();
        }
    smoothAct->setEnabled(true);
    brightAct->setEnabled(true);
    // Update the status bar with image size.
    QString statusShow = "Image Size: ("+QString::number(imSize.width())+", "+QString::number(imSize.height())+")";
    //statusBar()->showMessage(statusShow);
    statusBarNotification->setText(statusShow);

    }
}

void ImageViewer::zoomIn()
{
    scaleImage(1.25);
}

void ImageViewer::zoomOut()
{
    scaleImage(0.8);
}

void ImageViewer::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void ImageViewer::fitToWindow()
{
    bool fitToWindow = fitToWindowAct->isChecked();
    scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow) {
        normalSize();
    }
    updateActions();
}

void ImageViewer::updateActions()
{
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
}

void ImageViewer::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void ImageViewer::saveAs()
{
    Q_ASSERT(imageLabel->pixmap());
    QString filename = QFileDialog::getSaveFileName(this,
            tr("Save File"),
            QDir::currentPath(),
            "Images (*.png *.bmp *.jpg *.tif);");
    QImage thisImage = imageLabel->pixmap()->toImage();
    if (!thisImage.save(filename))
    {
        QMessageBox::information(this, tr("Image Viewer"),
                                 tr("Did not save file."));
        return;
    }
}

void ImageViewer::smoothCB()
{
    imageSmoother* smoother = new imageSmoother;
    smoother->setImage(&im);
    smoother->smoothed(5);

    imageLabel->setPixmap(QPixmap::fromImage(im.toQImage()));
    imageLabel->resize(imageLabel->pixmap()->size());
    delete smoother;
}

void ImageViewer::brightCB()
{
    imageBrightener* brighter = new imageBrightener;
    brighter->setImage(&im);
    brighter->brighten(5);

    imageLabel->setPixmap(QPixmap::fromImage(im.toQImage()));
    imageLabel->resize(imageLabel->pixmap()->size());
    delete brighter;
}

// Actions in the Help menu.
void ImageViewer::about()
{
    QMessageBox::about(this, tr("About Image Viewer"),
    tr("<p>The <b>Image Viewer</b> uses QT 4.8 and includes "
    "several image manipulation features. "
    "This is an extended version of the online example,"
    "available at <a>http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html</a>"
    "</p>"));
}
