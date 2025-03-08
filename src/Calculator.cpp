#include "../include/Calculator.h"

Calculator::Calculator(MainWindow* mainWindow){
    this->mainWindow = mainWindow;
    bool readStatus = readConfig();//3
    if(!readStatus){
        delayMilliseconds = 0;
    }
    connect(mainWindow,&MainWindow::calculationRequest, this, &Calculator::calculate);
    connect(mainWindow,&MainWindow::reloadDelayRequest, this, &Calculator::reloadDelay);
}

void Calculator::setConfigFile(QString fileConfigName){
    //Default name is "../../config.json"
    this->fileConfigName = fileConfigName;
}
// this is calculator



//private methods:
QSharedPointer<TaskResponse> Calculator::makeSafeOperation(QSharedPointer<TaskRequest> taskRequestPtr){
    /*Made safe required operation*/
    int val1 = taskRequestPtr->val1;
    int val2 = taskRequestPtr->val2;
    Operation operation = taskRequestPtr->operation;

    int resultInt=0;
    float resultFloat=0;
    QString resultOperationStr="";
    bool statusOperationBool=true;
    QString statusOperationStr="";
    QString operationStr="";

    switch (operation) {
    case Operation::add:
        operationStr = QString::number(val1) + " + " + QString::number(val2);
        if(__builtin_add_overflow(val1, val2, &resultInt)){
            resultOperationStr = "Overflow";
            statusOperationStr = "Error";
            statusOperationBool = false;
        }
        break;
    case Operation::subtract:
        operationStr = QString::number(val1) + " - " + QString::number(val2);
        if(__builtin_sub_overflow(val1, val2, &resultInt)){
            resultOperationStr = "Overflow";
            statusOperationStr = "Error";
            statusOperationBool = false;
        }
        break;
    case Operation::multiply:
        operationStr = QString::number(val1) + " * " + QString::number(val2);
        if(__builtin_mul_overflow(val1, val2, &resultInt)){
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
        else{
            resultFloat = (float)val1/(float)val2;
        }
        break;
    default:
        operationStr = "Operation do not recognized";
        resultOperationStr = "Error";
        statusOperationStr = "Error";
        statusOperationBool = false;
        break;
    }
    if(statusOperationBool){
        if(operation==Operation::divide){
            resultOperationStr = QString::number(resultFloat);
        }else{
            resultOperationStr = QString::number(resultInt);
        }
        statusOperationStr = "Success";
    }
    return  QSharedPointer<TaskResponse>::create(operationStr,statusOperationStr,resultOperationStr);
}


bool Calculator::readConfig(){//1
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

    delayMilliseconds = (int)jsonObj["delayMilliseconds"].toDouble();  // to convert non-integer values
    if(delayMilliseconds<0){
        qDebug() << "Delay must be positive value.";
        return false;
    }
    qDebug()<<"Correct load delay from file.";
    return true;
}


// slots:
void Calculator::calculate(QSharedPointer<TaskRequest> taskRequestPtr){
    if (QThread::currentThread()->isInterruptionRequested()) {
        return;// Sometimes even if thread was interrupted, tasks tasks continued to be completed
    }

    auto returnedResponsePtr = makeSafeOperation(taskRequestPtr);
    emit calculationResponse(returnedResponsePtr);
    int i=0;
    i++;
    i++;
}

void Calculator::reloadDelay(){
    bool readStatus = readConfig();//2
    if(!readStatus){
        delayMilliseconds = 777;
    }
}


