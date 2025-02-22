#pragma once
#include "Operation.h"
#include <QMetaType>
struct TaskRequest{
private:
public:
    int val1;
    int val2;
    Operation operation;
    TaskRequest(int val1, int val2, Operation operation):
        val1(val1),
        val2(val2),
        operation(operation){
    }
};
