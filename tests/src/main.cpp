#include <QtTest/QtTest>
#include "../include/CalculatorTest.h"
#include "../include/MainWindowTest.h"
//QTEST_MAIN(CalculatorTest)

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    int status = 0;
    status |= QTest::qExec(new CalculatorTest, argc, argv);
    status |= QTest::qExec(new MainWindowTest, argc, argv);
    return status;
}
