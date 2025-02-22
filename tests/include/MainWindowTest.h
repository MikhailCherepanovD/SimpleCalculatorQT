#pragma once
#include <QtTest/QtTest>
#define private public
#include "../include/Operation.h"
#include "../include/mainwindow.h"
#include "../include/Calculator.h"
#include "../include/TaskRequest.h"
#include "../include/TaskResponse.h"
#include "ui_mainwindow.h"
class MainWindowTest: public QObject {
    Q_OBJECT
    const QString fileName = "../../config.json";
private slots:
    void makeOperations();
};
