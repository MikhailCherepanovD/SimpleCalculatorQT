#pragma once
#include <QtTest/QtTest>
#include <QSignalSpy>
#include <QVariant>
#include <QList>
#define private public
#include "../include/Operation.h"
#include "../include/Calculator.h"
#include "../include/TaskRequest.h"
#include "../include/TaskResponse.h"
#include "../include/mainwindow.h"
class CalculatorTest: public QObject {
    Q_OBJECT
    const QString fileName = "../../config.json";
private slots:
    void makeSafeOperation_AddBasicTest();
    void makeSafeOperation_AddNegativeTest();
    void makeSafeOperation_AddPredOverflowTest();
    void makeSafeOperation_AddOverflowTest();

    void makeSafeOperation_SubtractBasicTest();
    void makeSafeOperation_SubtractDiffSignTest();
    void makeSafeOperation_SubtractOverflowTest();

    void makeSafeOperation_MultiplyBasicTest();
    void makeSafeOperation_MultiplyDiffSignTest();
    void makeSafeOperation_MultiplyZeroTest();
    void makeSafeOperation_MultiplyOverflowTest();

    void makeSafeOperation_DivideIntResultTest();
    void makeSafeOperation_DivideFloatResultTest();
    void makeSafeOperation_DivideDivisionByZeroTest();
    void makeSafeOperation_DivideZeroInResultTest();

    void readConfig_MissingFileTest();
    void readConfig_EmptyFileTest();
    void readConfig_IncorrectJsonFileTest();
    void readConfig_StringValueDelayTest();
    void readConfig_IntValueDelayTest();
    void readConfig_FloatValueDelayTest();

    void calculate_CorrectCalculationTest();
};
