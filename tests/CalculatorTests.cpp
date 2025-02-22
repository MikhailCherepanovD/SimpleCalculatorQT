#include "CalculatorTest.h"


void CalculatorTest::makeSafeOperation_AddBasicTest(){
    auto tr = QSharedPointer<TaskRequest>::create(1,2,Operation::add);
    Calculator calculator(nullptr);
    auto actual = calculator.makeSafeOperation(tr);
    auto expected = QSharedPointer<TaskResponse>::create("1 + 2","Success","3");
    QCOMPARE(actual->operation, expected->operation);
    QCOMPARE(actual->status, expected->status);
    QCOMPARE(actual->result, expected->result);
}

void CalculatorTest::makeSafeOperation_AddNegativeTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(-100,-80,Operation::add);
    Calculator calculator(nullptr);
    auto actual = calculator.makeSafeOperation(tr)->result;
    auto expected = "-180";
    QCOMPARE(actual, expected);
}
void CalculatorTest::makeSafeOperation_AddPredOverflowTest(){
    auto tr =  QSharedPointer<TaskRequest>::create((long)pow(2,31)-2,1,Operation::add);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    int res = (long)pow(2,31)-1;
    QString expected = QString::number(res);
    QCOMPARE(actual, expected);
}

void CalculatorTest::makeSafeOperation_AddOverflowTest(){
    auto tr =  QSharedPointer<TaskRequest>::create((long)pow(2,31)-2,4,Operation::add);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString actual1 = calculator.makeSafeOperation(tr)->status;
    QString expected = "Overflow";
    QString expected1 = "Error";
    QCOMPARE(actual, expected);
    QCOMPARE(actual1, expected1);
}

//subtract
void CalculatorTest::makeSafeOperation_SubtractBasicTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(100,80,Operation::subtract);
    Calculator calculator(nullptr);
    auto actual = calculator.makeSafeOperation(tr);
    auto expected = TaskResponse("100 - 80","Success","20");
    QCOMPARE(actual->operation, expected.operation);
    QCOMPARE(actual->status, expected.status);
    QCOMPARE(actual->result, expected.result);
}
void CalculatorTest::makeSafeOperation_SubtractDiffSignTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(100,-80,Operation::subtract);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "180";
    QCOMPARE(actual, expected);
}
void CalculatorTest::makeSafeOperation_SubtractOverflowTest(){
    auto tr =  QSharedPointer<TaskRequest>::create((long)pow(2,31)-2,-4,Operation::subtract);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString actual1 = calculator.makeSafeOperation(tr)->status;
    QString expected = "Overflow";
    QString expected1 = "Error";
    QCOMPARE(actual, expected);
    QCOMPARE(actual1, expected1);
}

void CalculatorTest::makeSafeOperation_MultiplyBasicTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(9,5,Operation::multiply);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "45";
    QCOMPARE(actual, expected);
}
void CalculatorTest::makeSafeOperation_MultiplyDiffSignTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(-9,5,Operation::multiply);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "-45";
    QCOMPARE(actual, expected);
}

void CalculatorTest::makeSafeOperation_MultiplyZeroTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(0,5,Operation::multiply);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "0";
    QCOMPARE(actual, expected);
}
void CalculatorTest::makeSafeOperation_MultiplyOverflowTest(){
    auto tr =  QSharedPointer<TaskRequest>::create((long)pow(2,31)-10,(long)pow(2,31)-100,Operation::multiply);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "Overflow";
    QCOMPARE(actual, expected);
}

void CalculatorTest::makeSafeOperation_DivideIntResultTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(8,2,Operation::divide);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "4";
    QCOMPARE(actual, expected);
}
void CalculatorTest::makeSafeOperation_DivideFloatResultTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(10,4,Operation::divide);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "2.5";
    QCOMPARE(actual, expected);
}
void CalculatorTest::makeSafeOperation_DivideDivisionByZeroTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(10,0,Operation::divide);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "Division by zero";
    QCOMPARE(actual, expected);
}
void CalculatorTest::makeSafeOperation_DivideZeroInResultTest(){
    auto tr =  QSharedPointer<TaskRequest>::create(0,10,Operation::divide);
    Calculator calculator(nullptr);
    QString actual = calculator.makeSafeOperation(tr)->result;
    QString expected = "0";
    QCOMPARE(actual, expected);
}

// load delay tests:
void CalculatorTest::readConfig_MissingFileTest(){
    QFile::remove(fileName);
    Calculator calculator(nullptr);
    auto actualStatus = calculator.readConfig();
    auto actualDelay = calculator.delayMilliseconds;

    QCOMPARE(actualStatus, false);
    QCOMPARE(actualDelay, 0);
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.close();
}
void CalculatorTest::readConfig_EmptyFileTest(){
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    Calculator calculator(nullptr);
    auto actualStatus = calculator.readConfig();
    auto actualDelay = calculator.delayMilliseconds;

    QCOMPARE(actualStatus, false);
    QCOMPARE(actualDelay, 0);

    file.close();
}
void CalculatorTest::readConfig_IncorrectJsonFileTest(){
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QString config = "{\n\"delayMilliseconds\" 500\n}";
    out << config;

    Calculator calculator(nullptr);
    auto actualStatus = calculator.readConfig();
    auto actualDelay = calculator.delayMilliseconds;

    QCOMPARE(actualStatus, false);
    QCOMPARE(actualDelay, 0);

    file.close();
}
void CalculatorTest::readConfig_StringValueDelayTest(){
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QString config = "{\n\"delayMilliseconds\": \"str\"\n}";
    out << config;
    file.close();
    Calculator calculator(nullptr);
    calculator.fileConfigName = fileName;
    auto actualStatus = calculator.readConfig();
    auto actualDelay = calculator.delayMilliseconds;

    QCOMPARE(actualStatus, false);
    QCOMPARE(actualDelay, 0);


}
void CalculatorTest::readConfig_IntValueDelayTest(){
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QString config = "{\n\"delayMilliseconds\": 500 \n}";
    out << config;
    file.close();
    Calculator calculator(nullptr);
    calculator.fileConfigName = fileName;
    auto actualStatus = calculator.readConfig();
    auto actualDelay = calculator.delayMilliseconds;
    QCOMPARE(actualStatus, true);
    QCOMPARE(actualDelay, 500);

}

void CalculatorTest::readConfig_FloatValueDelayTest(){
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QString config = "{\n\"delayMilliseconds\": 500.564 \n}";
    out << config;
    file.close();
    Calculator calculator(nullptr);
    calculator.fileConfigName = fileName;
    auto actualStatus = calculator.readConfig();
    auto actualDelay = calculator.delayMilliseconds;
    QCOMPARE(actualStatus, true);
    QCOMPARE(actualDelay, 500);
}

//Calculate tests
void CalculatorTest::calculate_CorrectCalculationTest(){
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QString config = "{\n\"delayMilliseconds\": 500 \n}";
    out << config;
    file.close();

    MainWindow mw;
    Calculator calculator(&mw);
    QSignalSpy spy(&calculator, SIGNAL(calculationResponse(QSharedPointer<TaskResponse>)));
    auto taskRequest = QSharedPointer<TaskRequest>::create(2,3,Operation::add);
    emit mw.calculationRequest(taskRequest);
    QThread::sleep(1);//exactly finished
    QCOMPARE(spy.count(), 1);
    QList<QVariant> arguments = spy.takeFirst();
    auto actualResponse = arguments.at(0).value<QSharedPointer<TaskResponse>>();
    auto expectedResponse = TaskResponse(QString("2 + 3"),QString("Success"),QString("5"));
    QCOMPARE(actualResponse->operation, expectedResponse.operation);
    QCOMPARE(actualResponse->status, expectedResponse.status);
}

