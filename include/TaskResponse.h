#pragma once
#include <QString>
#include <QMetaType>
struct TaskResponse{
public:
    QString operation;
    QString status;
    QString result;
    TaskResponse(){}
    TaskResponse(QString operation, QString status,QString result):
        operation(operation),
        status(status),
        result(result){}
};
