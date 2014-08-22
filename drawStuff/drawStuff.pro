#-------------------------------------------------
#
# Project created by QtCreator 2014-06-29T00:19:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drawStuff
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    canvas.cpp \
    mainwindow.cpp \
    linedialog.cpp \
    shape2d.cpp \
    polylinedialog.cpp \
    csys2ddialog.cpp

HEADERS  += window.h \
    canvas.h \
    mainwindow.h \
    linedialog.h \
    shape2d.h \
    polylinedialog.h \
    csys2ddialog.h

FORMS    += window.ui \
    linedialog.ui \
    polylinedialog.ui \
    csys2ddialog.ui
