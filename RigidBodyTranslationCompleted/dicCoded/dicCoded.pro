#-------------------------------------------------
#
# Project created by QtCreator 2013-05-23T19:57:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dicCoded
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    ellipticfixedsizedialog.cpp \
    platesizedialog.cpp \
    rigidbodytranslation.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    ellipticfixedsizedialog.h \
    platesizedialog.h \
    rigidbodytranslation.h

FORMS    += mainwindow.ui \
    ellipticfixedsizedialog.ui \
    platesizedialog.ui \
    rigidbodytranslation.ui
