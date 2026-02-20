QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chessclock
TEMPLATE = app

SOURCES += \
    main.cpp \
    chessclock.cpp

HEADERS += \
    mainwindow.h \

FORMS += \
    mainwindow.ui