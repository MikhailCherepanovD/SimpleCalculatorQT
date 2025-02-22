#pragma once
#include <QtTest/QtTest>
#define private public
#include "../Operation.h"
#include "../mainwindow.h"
#include "../Calculator.h"
#include "../TaskRequest.h"
#include "../TaskResponse.h"
#include "ui_mainwindow.h"
class MainWindowTest: public QObject {
    Q_OBJECT
    const QString fileName = "../../config.json";
private slots:
    void addCorrectValues();
};
