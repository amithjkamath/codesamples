#-------------------------------------------------
#
# Project created by QtCreator 2014-08-03T23:23:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS    += -lopencv_core
LIBS    += -lopencv_highgui
LIBS    += -lopencv_imgproc

TARGET = opencvQt
TEMPLATE = app


SOURCES += main.cpp\
    image.cpp \
    imageviewer.cpp \
    imagesmoother.cpp \
    imagebrightener.cpp

HEADERS  += \
    image.h \
    imageviewer.h \
    imagesmoother.h \
    imagebrightener.h

FORMS    +=
