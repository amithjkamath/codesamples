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

 #ifndef IMAGEVIEWER_H
 #define IMAGEVIEWER_H

 #include <QMainWindow>
 #include <QPrinter>

 class QAction;
 class QLabel;
 class QMenu;
 class QScrollArea;
 class QScrollBar;

 class ImageViewer : public QMainWindow // inherits from QMainWindow
 {
     Q_OBJECT

 public:
     // only public function is the constructor.
     ImageViewer();

 private slots:
     // File menu
     void open();
     void print();
     void saveAs();
     // View menu
     void zoomIn();
     void zoomOut();
     void normalSize();
     void fitToWindow();
     // Edit menu
     void invertImage();
     void incBright();
     void decBright();
     void sharpen();
     void blur();
     void greyscale();
     void incSaturation();
     void decSaturation();
     // Help menu
     void about();

 private:
     // Private function members.
     // Helpers for zoom actions.
     void updateActions();
     void scaleImage(double factor);

     // Helpers for editing.
     void changeBrightness(QImage &thisImage, int delta);
     void changeSaturation(QImage &thisImage, int delta);
     void filterImage(QImage &thisImage, int kernel[5][5], int kernelSize, int sumKernel);

     // Helpers for constructor.
     void createActions();
     void createMenus();
     void adjustScrollBar(QScrollBar *scrollBar, double factor);

     // Private data members.
     //QLabel to store the image itself.
     QLabel *imageLabel;
     // QScrollArea to create the scrollable area.
     QScrollArea *scrollArea;
     double scaleFactor;

    #ifndef QT_NO_PRINTER
     QPrinter printer;
    #endif
     // The menus themselves
     QMenu *fileMenu;
     QMenu *viewMenu;
     QMenu *editMenu;
     QMenu *helpMenu;

     // File menu
     QAction *openAct;
     QAction *printAct;
     QAction *saveAsAct;
     QAction *exitAct;
     // View menu
     QAction *zoomInAct;
     QAction *zoomOutAct;
     QAction *normalSizeAct;
     QAction *fitToWindowAct;
     // Edit menu
     QAction *invertImageAct;
     QAction *increaseBrightnessAct;
     QAction *decreaseBrightnessAct;
     QAction *sharpenAct;
     QAction *blurAct;
     QAction *greyscaleAct;
     QAction *increaseSaturationAct;
     QAction *decreaseSaturationAct;
     // Help menu
     QAction *aboutAct;
     QAction *aboutQtAct;
 };

 #endif
