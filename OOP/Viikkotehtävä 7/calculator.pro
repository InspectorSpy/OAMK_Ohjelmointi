QT += core gui widgets

greaterThan (QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app

SOURCES += \
    main.cpp \
    calculator.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui