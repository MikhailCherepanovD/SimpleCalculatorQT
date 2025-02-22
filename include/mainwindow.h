#pragma once
#define QT_USE_QSTRINGBUILDER
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QQueue>
#include <QThread>
#include <QSharedPointer>
#include "Operation.h"
#include "Calculator.h"
#include "TaskRequest.h"
#include "TaskResponse.h"


class Calculator;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Calculator* calculator;
    Ui::MainWindow *ui;
    QThread* calculationThread;
    QQueue<int> queueProcessingTaskId;
    void lauchCalculate(Operation operation);
signals:
    void calculationRequest(QSharedPointer<TaskRequest> taskRequestPtr);
    void reloadDelayRequest();
public slots:
    void outputResponse(QSharedPointer<TaskResponse> taskResponsePtr);
};
