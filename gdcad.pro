#-------------------------------------------------
#
# Project created by QtCreator 2014-06-23T00:27:11
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gdcad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gdkernel/circle.cpp \
     gdkernel/ellipse.cpp \
     gdkernel/point.cpp \
     gdkernel/line.cpp \
     gdkernel/arc.cpp

HEADERS  += mainwindow.h \
     gdkernel/circle.h \
     gdkernel/ellipse.h \
     gdkernel/point.h \
     gdkernel/line.h \
     gdkernel/arc.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
