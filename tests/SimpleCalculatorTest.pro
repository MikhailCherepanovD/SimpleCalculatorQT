QT       += core gui testlib  # List of modules

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


HEADERS += \
    ../include/Calculator.h \
    ../include/Operation.h \
    ../include/TaskRequest.h \
    ../include/TaskResponse.h \
    ../include/mainwindow.h \
    include/CalculatorTest.h \
    include/MainWindowTest.h

SOURCES += \
    ../src/mainwindow.cpp \
    ../src/Calculator.cpp \
    src/CalculatorTests.cpp \
    src/MainWindowTest.cpp \
    src/main.cpp

FORMS += \
    ../mainwindow.ui
