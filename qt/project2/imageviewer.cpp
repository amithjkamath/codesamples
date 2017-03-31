/****************************************************************************
 **
 ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
 ** Contact: http://www.qt-project.org/legal
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:BSD$
 ** You may use this file under the terms of the BSD license as follows:
 **
 ** "Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **   * Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **   * Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in
 **     the documentation and/or other materials provided with the
 **     distribution.
 **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
 **     of its contributors may be used to endorse or promote products derived
 **     from this software without specific prior written permission.
 **
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

 #include <QtGui>

 #include "imageviewer.h"

 //Constructor for the ImageViewer Class.
 ImageViewer::ImageViewer()
 {
     // QLabel is used for displaying text or an image.
     // No user interaction functionality is provided.
     imageLabel = new QLabel;
     imageLabel->setBackgroundRole(QPalette::Base);
     imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
     imageLabel->setScaledContents(true);

     // QScrollArea provides a scrolling view around another widget.
     // If the child widget exceeds the size of the frame, QScrollArea
     // automatically provides scroll bars.
     scrollArea = new QScrollArea;
     scrollArea->setBackgroundRole(QPalette::Dark);
     scrollArea->setWidget(imageLabel);
     setCentralWidget(scrollArea);

     createActions();
     createMenus();

     setWindowTitle(tr("Image Viewer"));
     resize(500, 500);
 }

 // Helpers for the constructor.
 void ImageViewer::createActions()
 {
     // File menu actions.
     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcut(tr("Ctrl+O"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     printAct = new QAction(tr("&Print..."), this);
     printAct->setShortcut(tr("Ctrl+P"));
     printAct->setEnabled(false);
     connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

     saveAsAct = new QAction(tr("&Save As..."), this);
     saveAsAct->setShortcut(tr("Ctrl+S"));
     saveAsAct->setEnabled(false);
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcut(tr("Ctrl+Q"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     // Zoom menu actions.
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

     // Edit menu actions.
     invertImageAct = new QAction(tr("&Invert Image"), this);
     invertImageAct->setShortcut(tr("Ctrl+I"));
     invertImageAct->setEnabled(false);
     connect(invertImageAct, SIGNAL(triggered()), this, SLOT(invertImage()));

     increaseBrightnessAct = new QAction(tr("&Increase Brightness"), this);
     increaseBrightnessAct->setShortcut(tr("Ctrl+U"));
     increaseBrightnessAct->setEnabled(false);
     connect(increaseBrightnessAct, SIGNAL(triggered()), this, SLOT(incBright()));

     decreaseBrightnessAct = new QAction(tr("&Decrease Brightness"), this);
     decreaseBrightnessAct->setShortcut(tr("Ctrl+J"));
     decreaseBrightnessAct->setEnabled(false);
     connect(decreaseBrightnessAct, SIGNAL(triggered()), this, SLOT(decBright()));

     sharpenAct = new QAction(tr("&Sharpen"), this);
     sharpenAct->setShortcut(tr("Ctrl+H"));
     sharpenAct->setEnabled(false);
     connect(sharpenAct, SIGNAL(triggered()), this, SLOT(sharpen()));

     blurAct = new QAction(tr("&Blur"), this);
     blurAct->setShortcut(tr("Ctrl+B"));
     blurAct->setEnabled(false);
     connect(blurAct, SIGNAL(triggered()), this, SLOT(blur()));

     greyscaleAct = new QAction(tr("&Greyscale"), this);
     greyscaleAct->setShortcut(tr("Ctrl+G"));
     greyscaleAct->setEnabled(false);
     connect(greyscaleAct, SIGNAL(triggered()), this, SLOT(greyscale()));

     increaseSaturationAct = new QAction(tr("&Increase Saturation"), this);
     increaseSaturationAct->setShortcut(tr("Ctrl+Q"));
     increaseSaturationAct->setEnabled(false);
     connect(increaseSaturationAct, SIGNAL(triggered()), this, SLOT(incSaturation()));

     decreaseSaturationAct = new QAction(tr("&Decrease Saturation"), this);
     decreaseSaturationAct->setShortcut(tr("Ctrl+A"));
     decreaseSaturationAct->setEnabled(false);
     connect(decreaseSaturationAct, SIGNAL(triggered()), this, SLOT(decSaturation()));

     // Help menu actions.
     aboutAct = new QAction(tr("&About"), this);
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("About &Qt"), this);
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
 }

 void ImageViewer::createMenus()
 {
     // called in the constructor.
     fileMenu = new QMenu(tr("&File"), this);
     fileMenu->addAction(openAct);
     fileMenu->addAction(printAct);
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
     editMenu->addAction(invertImageAct);
     editMenu->addAction(increaseBrightnessAct);
     editMenu->addAction(decreaseBrightnessAct);
     editMenu->addAction(sharpenAct);
     editMenu->addAction(blurAct);
     editMenu->addAction(greyscaleAct);
     editMenu->addAction(increaseSaturationAct);
     editMenu->addAction(decreaseSaturationAct);

     helpMenu = new QMenu(tr("&Help"), this);
     helpMenu->addAction(aboutAct);
     helpMenu->addAction(aboutQtAct);

     // Do this after, because the Actions need to be added first.
     menuBar()->addMenu(fileMenu);
     menuBar()->addMenu(viewMenu);
     menuBar()->addMenu(editMenu);
     menuBar()->addMenu(helpMenu);
 }

 void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
 {
     scrollBar->setValue(int(factor * scrollBar->value()
                             + ((factor - 1) * scrollBar->pageStep()/2)));
 }


 // Actions in the file menu.
 void ImageViewer::open()
 {
     QString fileName = QFileDialog::getOpenFileName(this,
                                     tr("Open File"), QDir::currentPath());
     if (!fileName.isEmpty()) {
         QImage image(fileName);
         if (image.isNull()) {
             QMessageBox::information(this, tr("Image Viewer"),
                                      tr("Cannot load %1.").arg(fileName));
             return;
         }
         imageLabel->setPixmap(QPixmap::fromImage(image));
         // enable printing once image is loaded.
         printAct->setEnabled(true);
         saveAsAct->setEnabled(true);
         // enable zoom actions.
         scaleFactor = 1.0;
         fitToWindowAct->setEnabled(true);
         updateActions();

         if (!fitToWindowAct->isChecked())
             imageLabel->adjustSize();

         // emable edit actions.
         invertImageAct->setEnabled(true);
         increaseBrightnessAct->setEnabled(true);
         decreaseBrightnessAct->setEnabled(true);
         sharpenAct->setEnabled(true);
         blurAct->setEnabled(true);
         greyscaleAct->setEnabled(true);
         increaseSaturationAct->setEnabled(true);
         decreaseSaturationAct->setEnabled(true);
     }
 }

 void ImageViewer::print()
 {
     Q_ASSERT(imageLabel->pixmap());
 #ifndef QT_NO_PRINTER
     QPrintDialog dialog(&printer, this);
     if (dialog.exec()) {
         QPainter painter(&printer);
         QRect rect = painter.viewport();
         QSize size = imageLabel->pixmap()->size();
         size.scale(rect.size(), Qt::KeepAspectRatio);
         painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
         painter.setWindow(imageLabel->pixmap()->rect());
         painter.drawPixmap(0, 0, *imageLabel->pixmap());
     }
 #endif
 }

 void ImageViewer::saveAs()
 {
     Q_ASSERT(imageLabel->pixmap());
     QString filename = QFileDialog::getSaveFileName(this,
             tr("Save File"),
             QDir::currentPath(),
             "Images (*.png *.bmp *.jpg *.tif);");
     QImage thisImage = imageLabel->pixmap()->toImage();
     if (!thisImage.save(filename)) {
         QMessageBox::information(this, tr("Image Viewer"),
                                  tr("Did not save file."));
         return;
     }
 }

 // Actions in the Zoom menu.
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

 // Helper for zoom actions.
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

 void ImageViewer::updateActions()
 {
     zoomInAct->setEnabled(!fitToWindowAct->isChecked());
     zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
     normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
 }

 // Actions in the Edit menu.
 void ImageViewer::invertImage()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     thisImage.invertPixels();
     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::incBright()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     changeBrightness(thisImage, 5);
     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::decBright()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     changeBrightness(thisImage, -5);
     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::changeBrightness(QImage& thisImage, int delta)
 {
     thisImage.convertToFormat(QImage::Format_ARGB32);
     QColor oldColor;
         int r,g,b;
         for(int x=0; x<thisImage.width(); x++){
             for(int y=0; y<thisImage.height(); y++){
                 oldColor = QColor(thisImage.pixel(x,y));

                 r = oldColor.red() + delta;
                 g = oldColor.green() + delta;
                 b = oldColor.blue() + delta;

                 //we check if the new values are between 0 and 255
                 r = qBound(0, r, 255);
                 g = qBound(0, g, 255);
                 b = qBound(0, b, 255);

                 thisImage.setPixel(x,y, qRgb(r,g,b));
             }
         }
         QPixmap mypixmap = QPixmap::fromImage(thisImage);
         imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::sharpen()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     int kernel [5][5]= {{0, 0, 0, 0, 0},
                         {0, 0,-1, 1, 0},
                         {0,-1, 5,-1, 0},
                         {0, 0,-1, 0, 0},
                         {0, 0, 0, 0, 0}};
     int kernelSize = 5;
     int sumKernel = 1;
     filterImage(thisImage,kernel,kernelSize,sumKernel);
     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::blur()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     int kernel [5][5]= {{0,0,1,0,0},
                         {0,1,3,1,0},
                         {1,3,7,3,1},
                         {0,1,3,1,0},
                         {0,0,1,0,0}};
     int kernelSize = 5;
     int sumKernel = 27;
     filterImage(thisImage,kernel,kernelSize,sumKernel);
     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::filterImage(QImage &thisImage, int kernel[][5], int kernelSize, int sumKernel)
 {
     int r,g,b;
     QColor color;

     for(int x = kernelSize/2; x < thisImage.width()-(kernelSize/2); x++){
         for(int y = kernelSize/2; y < thisImage.height()-(kernelSize/2); y++){

             r = 0;
             g = 0;
             b = 0;

             for(int i = -kernelSize/2; i <= kernelSize/2; i++){
                 for(int j = -kernelSize/2; j <= kernelSize/2; j++){
                     color = QColor(thisImage.pixel(x+i, y+j));
                     r += color.red()*kernel[kernelSize/2+i][kernelSize/2+j];
                     g += color.green()*kernel[kernelSize/2+i][kernelSize/2+j];
                     b += color.blue()*kernel[kernelSize/2+i][kernelSize/2+j];
                 }
             }

             r = qBound(0, r/sumKernel, 255);
             g = qBound(0, g/sumKernel, 255);
             b = qBound(0, b/sumKernel, 255);

             thisImage.setPixel(x,y,qRgb(r,g,b));
         }
     }
 }

 void ImageViewer::greyscale()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     QColor oldColor;

     for(int x = 0; x < thisImage.width(); x++){
         for(int y = 0; y < thisImage.height(); y++){
             oldColor = QColor(thisImage.pixel(x,y));
             int average = (oldColor.red()+oldColor.green()+oldColor.blue())/3;
             thisImage.setPixel(x,y,qRgb(average,average,average));
         }
     }

     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::incSaturation()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     changeSaturation(thisImage, 5);
     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

 void ImageViewer::decSaturation()
 {
     Q_ASSERT(imageLabel->pixmap());
     QImage thisImage = imageLabel->pixmap()->toImage();
     changeSaturation(thisImage, -5);
     QPixmap mypixmap = QPixmap::fromImage(thisImage);
     imageLabel->setPixmap(mypixmap);
 }

void ImageViewer::changeSaturation(QImage &thisImage, int delta)
{
    QColor oldColor;
    QColor newColor;
    int h,s,l;

    for(int x=0; x < thisImage.width(); x++){
        for(int y=0; y < thisImage.height(); y++){
            oldColor = QColor(thisImage.pixel(x,y));

            newColor = oldColor.toHsl();
            h = newColor.hue();
            s = newColor.saturation()+delta;
            l = newColor.lightness();

            //we check if the new value is between 0 and 255
            s = qBound(0, s, 255);

            newColor.setHsl(h, s, l);

            thisImage.setPixel(x, y, qRgb(newColor.red(), newColor.green(), newColor.blue()));
        }
    }
}

 // Actions in the Help menu.
 void ImageViewer::about()
 {
     QMessageBox::about(this, tr("About Image Viewer"),
             tr("<p>The <b>Image Viewer</b> example shows how to combine QLabel "
                "and QScrollArea to display an image. QLabel is typically used "
                "for displaying a text, but it can also display an image. "
                "QScrollArea provides a scrolling view around another widget. "
                "If the child widget exceeds the size of the frame, QScrollArea "
                "automatically provides scroll bars. </p><p>The example "
                "demonstrates how QLabel's ability to scale its contents "
                "(QLabel::scaledContents), and QScrollArea's ability to "
                "automatically resize its contents "
                "(QScrollArea::widgetResizable), can be used to implement "
                "zooming and scaling features. </p><p>In addition the example "
                "shows how to use QPainter to print an image."
                "This is an extended version of the online example."
                "</p>"));
 }
