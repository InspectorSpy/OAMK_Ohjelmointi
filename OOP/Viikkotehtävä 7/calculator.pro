QT += core gui widgets

greaterThan (QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui