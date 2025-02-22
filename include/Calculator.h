#pragma once
#define CALCULATOR_H
#include <QObject>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSharedPointer>
#include "TaskRequest.h"
#include "TaskResponse.h"
#include "Operation.h"
#include "mainwindow.h"
class MainWindow;
class Calculator: public QObject
{
    Q_OBJECT
    QString fileConfigName = "../../config.json";
    // curr dir is path_to_project/build/Desktop-Debug
    int delayMilliseconds;
    MainWindow* mainWindow;

    QSharedPointer<TaskResponse> makeSafeOperation(QSharedPointer<TaskRequest> taskRequestPtr);
    bool readConfig();// true - correct read file, false - incorrect read file
public:
    Calculator(MainWindow* mainWindow);
    void setConfigFile(QString fileConfigName);
signals:
    void calculationResponse(QSharedPointer<TaskResponse> taskResponsePtr);
public slots:
    void calculate(QSharedPointer<TaskRequest> taskRequestPtr);
    void reloadDelay();
};

