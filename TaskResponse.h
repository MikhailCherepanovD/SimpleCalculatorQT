#pragma once
#include <QString>
struct TaskResponse{
public:
    QString operation;
    QString status;
    QString result;
    TaskResponse(QString operation, QString status,QString result):
        operation(operation),
        status(status),
        result(result){}
};
