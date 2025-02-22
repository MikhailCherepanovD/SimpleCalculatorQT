#include "../include/MainWindowTest.h"

void MainWindowTest::makeOperations(){

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QString config = "{\n\"delayMilliseconds\": 1000 \n}";
    out << config;
    file.close();


    MainWindow window;
    window.show();
    QTest::keyClicks(window.ui->argLineEdit1, "1");
    QTest::keyClicks(window.ui->argLineEdit2, "2");

    QCOMPARE(window.ui->argLineEdit1->text(), QString("1"));
    QCOMPARE(window.ui->argLineEdit2->text(), QString("2"));

    QTest::mouseClick(window.ui->addPushButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->subtractPushButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->multiplyPushButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->dividePushButton, Qt::LeftButton);
    QTest::qWait(5000);

    window.ui->argLineEdit2->clear();
    QTest::keyClicks(window.ui->argLineEdit2, "0");
    QTest::mouseClick(window.ui->dividePushButton, Qt::LeftButton);
    QTest::qWait(1500);
    QCOMPARE(window.ui->outputListWidget->count(), 5);

    QCOMPARE(window.ui->outputListWidget->item(0)->text(),
             QString("Expression: 1 + 2; Status: Success; Result: 3"));
    QCOMPARE(window.ui->outputListWidget->item(1)->text(),
             QString("Expression: 1 - 2; Status: Success; Result: -1"));
    QCOMPARE(window.ui->outputListWidget->item(2)->text(),
             QString("Expression: 1 * 2; Status: Success; Result: 2"));
    QCOMPARE(window.ui->outputListWidget->item(3)->text(),
             QString("Expression: 1 / 2; Status: Success; Result: 0.5"));
    QCOMPARE(window.ui->outputListWidget->item(4)->text(),
             QString("Expression: 1 / 0; Status: Error; Result: Division by zero"));
}
