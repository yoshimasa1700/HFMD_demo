#-------------------------------------------------
#
# Project created by QtCreator 2013-05-06T14:56:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HFMD_demo
TEMPLATE = app

INCLUDEPATH += /usr/include/libusb-1.0 /usr/include/openni /usr/include/ni
LIBS += -L/usr/lib -lOpenNI -lusb-1.0  -lboost_system -lboost_date_time -lboost_thread


SOURCES += main.cpp\
        mainwindow.cpp \
    ctlkinect.cpp \
    dialog.cpp \
    settingdialog.cpp \
    source/CDataset.cpp \
    source/CRForest.cpp \
    source/CRTree.cpp \
    source/HoG.cpp \
    source/util.cpp

HEADERS  += mainwindow.h \
    ctlkinect.h \
    dialog.h \
    settingdialog.h \
    source/CDataset.h \
    source/CPatch.h \
    source/CRForest.h \
    source/CRTree.h \
    source/HoG.h \
    source/detectionresult.h \
    source/util.h

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
