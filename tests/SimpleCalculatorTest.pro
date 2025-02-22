QT       += core gui testlib  # List of modules

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


HEADERS += \
    ../Calculator.h \
    ../Operation.h \
    ../TaskRequest.h \
    ../TaskResponse.h \
    ../mainwindow.h \
    CalculatorTest.h \
    MainWindowTest.h

SOURCES += \
    ../mainwindow.cpp \
    ../Calculator.cpp \
    CalculatorTests.cpp \
    MainWindowTest.cpp \
    main.cpp

FORMS += \
    ../mainwindow.ui
