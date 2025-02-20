#pragma once
#define CALCULATOR_H
#include <QObject>
#include <QVector>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringListModel>
#include "TaskRequest.h"
#include "TaskResponse.h"
#include "Operation.h"
#include "mainwindow.h"
class MainWindow;
class Calculator: public QObject
{
    Q_OBJECT
    const QString fileConfigName = "/home/mikhail/development/QTProjects/ISTA/config.json";
    int delayMilliseconds;
    MainWindow* mainWindow;

    TaskResponse makeSafeOperation(TaskRequest taskRequest);
    bool readConfig();// true - correct read file, false - incorrect read file
public:
    Calculator(MainWindow* mainWindow);
signals:
    void calculationResponse(TaskResponse taskResponse);
public slots:
    void calculate(TaskRequest taskRequest);
    void reloadDelay();
};

