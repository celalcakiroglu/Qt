#-------------------------------------------------
#
# Project created by QtCreator 2013-03-15T14:33:23
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ellipticfixedsize.cpp \
    mypanelopengl.cpp

HEADERS  += mainwindow.h \
    ellipticfixedsize.h \
    mypanelopengl.h

FORMS    += mainwindow.ui \
    ellipticfixedsize.ui

RESOURCES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lapackBinaries/lib/ -llibblas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lapackBinaries/lib/ -llibblas
else:unix: LIBS += -L$$PWD/../../lapackBinaries/lib/ -llibblas

INCLUDEPATH += $$PWD/../../lapackBinaries
DEPENDPATH += $$PWD/../../lapackBinaries

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lapackBinaries/lib/ -lliblapack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lapackBinaries/lib/ -lliblapack
else:unix: LIBS += -L$$PWD/../../lapackBinaries/lib/ -lliblapack

INCLUDEPATH += $$PWD/../../lapackBinaries
DEPENDPATH += $$PWD/../../lapackBinaries

