#-------------------------------------------------
#
# Project created by QtCreator 2013-05-06T14:56:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = grabRGBD
TEMPLATE = app

INCLUDEPATH += /usr/include/libusb-1.0 /usr/include/openni
LIBS += -L/usr/lib -lOpenNI -lusb-1.0  -lboost_system -lboost_date_time -lboost_thread


SOURCES += main.cpp\
        mainwindow.cpp \
    ctlkinect.cpp \
    util.cpp \
    HoG.cpp \
    CRTree.cpp \
    CRForest.cpp \
    detectionresult.cpp \
    dialog.cpp \
    settingdialog.cpp

HEADERS  += mainwindow.h \
    ctlkinect.h \
    util.h \
    HoG.h \
    CRTree.h \
    CRForest.h \
    CPatch.h \
    detectionresult.h \
    dialog.h \
    settingdialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    settingdialog.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv

OTHER_FILES += \
    mainwindow.o \
    main.o \
    grabRGBD.pro.user \
    grabRGBD \
    ctlkinect.o \
    config.xml \
    Makefile \
    Config.xml

QMAKE_CXXFLAGS += -O3

unix: PKGCONFIG += opencv
