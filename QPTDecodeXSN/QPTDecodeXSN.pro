#-------------------------------------------------
#
# Project created by QtCreator 2019-02-11T12:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QPTDecodeXSN
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# OpencCV 2.4.13
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Code/Z_OPENCV/opencv2413/build/x64/vc12/lib/ \
                                              -lopencv_core2413 \
                                              -lopencv_imgproc2413 \
                                              -lopencv_highgui2413
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Code/Z_OPENCV/opencv2413/build/x64/vc12/lib/ \
                                              -lopencv_core2413d \
                                              -lopencv_imgproc2413d \
                                              -lopencv_highgui2413d
else:unix: LIBS += `pkg-config  --libs opencv`
unix:INCLUDEPATH += /usr/include/opencv
win32:INCLUDEPATH += $$PWD/../../../Code/Z_OPENCV/opencv2413/build/include
win32:DEPENDPATH += $$PWD/../../../Code/Z_OPENCV/opencv2413/build/include



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    xsndecoder.cpp

HEADERS += \
        mainwindow.h \
    xsndecoder.h

FORMS += \
        mainwindow.ui
