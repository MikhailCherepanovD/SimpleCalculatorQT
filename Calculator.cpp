#include "Calculator.h"

Calculator::Calculator(MainWindow* mainWindow){
    this->mainWindow = mainWindow;
    bool readStatus = readConfig();
    if(!readStatus){
        delayMilliseconds = 0;
    }
    connect(mainWindow,&MainWindow::calculationRequest, this, &Calculator::calculate);
    connect(mainWindow,&MainWindow::reloadDelayRequest, this, &Calculator::reloadDelay);
}

//private methods:
TaskResponse Calculator::makeSafeOperation(TaskRequest taskRequest){
    /*Made safe required operation*/
    int val1 = taskRequest.val1;
    int val2 = taskRequest.val2;
    Operation operation = taskRequest.operation;

    int result=0;
    QString resultOperationStr="";
    bool statusOperationBool=true;
    QString statusOperationStr="";
    QString operationStr="";

    switch (operation) {
    case Operation::add:
        operationStr = QString::number(val1) + " + " + QString::number(val2);
        if(__builtin_add_overflow(val1, val2, &result)){
            resultOperationStr = "Overflow";
            statusOperationStr = "Error";
            statusOperationBool = false;
        }
        break;
    case Operation::subtract:
        operationStr = QString::number(val1) + " - " + QString::number(val2);
        if(__builtin_sub_overflow(val1, val2, &result)){
            resultOperationStr = "Overflow";
            statusOperationStr = "Error";
            statusOperationBool = false;
        }
        break;
    case Operation::multiply:
        operationStr = QString::number(val1) + " * " + QString::number(val2);
        if(__builtin_mul_overflow(val1, val2, &result)){
            resultOperationStr = "Overflow";
            statusOperationStr = "Error";
            statusOperationBool = false;
        }
        break;
    case Operation::divide:
        operationStr = QString::number(val1) + " / " + QString::number(val2);
        if(val2==0){
            resultOperationStr = "Division by zero";
            statusOperationStr = "Error";
            statusOperationBool = false;
        }
        result = val1/val2;
        break;
    default:
        operationStr = "Operation do not recognized";
        resultOperationStr = "Error";
        statusOperationStr = "Error";
        statusOperationBool = false;
        break;
    }
    if(statusOperationBool){
        resultOperationStr = QString::number(result);
        statusOperationStr = "Success";
    }
    return TaskResponse(operationStr,statusOperationStr,resultOperationStr);;
}


bool Calculator::readConfig(){
    /*true - correct read file, false - incorrect read file*/
    QFile file(fileConfigName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {// file is readonly and contains text
        qDebug() << "Failed to open file.";
        return false;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (!jsonDoc.isObject()) {
        qDebug() << "Invalid JSON format.";
        return false;
    }

    QJsonObject jsonObj = jsonDoc.object();
    if(!jsonObj.contains("delayMilliseconds")){
        qDebug() << "Key 'delayMilliseconds' is missing.";
        return false;
    }

    if(!jsonObj["delayMilliseconds"].isDouble()){
        qDebug() << "Delay must be numeric.";
        return false;
    }

    delayMilliseconds = jsonObj["delayMilliseconds"].toInt();  // set 0 if this is non-convertable to int
    if(delayMilliseconds<0){
        qDebug() << "Delay must be positive value.";
        return false;
    }
    qDebug()<<"Correct load delay from file.";
    return true;
}


// slots:
void Calculator::calculate(TaskRequest taskRequest){
    if (QThread::currentThread()->isInterruptionRequested()) {
        return;// Sometimes even if thread was interrupted, tasks tasks continued to be completed
    }
    QThread::msleep(delayMilliseconds);
    TaskResponse taskResponse = makeSafeOperation(taskRequest);
    emit calculationResponse(taskResponse);
}

void Calculator::reloadDelay(){
    bool readStatus = readConfig();
    if(!readStatus){
        delayMilliseconds = 0;
    }
}


