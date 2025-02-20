#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calculator = new Calculator(this);
    calculationThread = new QThread();
    calculator->moveToThread(calculationThread);
    calculationThread->start();
    connect(ui->addPushButton,&QPushButton::clicked,[this](){
        lauchCalculate(Operation::add);
    });
    connect(ui->subtractPushButton,&QPushButton::clicked,[this](){
        lauchCalculate(Operation::subtract);
    });
    connect(ui->multiplyPushButton,&QPushButton::clicked,[this](){
        lauchCalculate(Operation::multiply);
    });
    connect(ui->dividePushButton,&QPushButton::clicked,[this](){
        lauchCalculate(Operation::divide);
    });
    connect(ui->reloadPushButton,&QPushButton::clicked,[this](){
        emit reloadDelayRequest();
    });
    connect(calculator,&Calculator::calculationResponse,this,&MainWindow::outputResponse);

}

MainWindow::~MainWindow()
{

    delete ui;
    delete calculator;
    if (calculationThread) {
        qDebug() << "Перед тем как кинули ожидание";
        calculationThread->quit();  // Завершаем event loop потока
        qDebug() << "Ожидаем завершение вычислений";
        calculationThread->wait();  // Ждём завершения потока
        qDebug() << "Перед удалением";
        delete calculationThread;   // Удаляем поток
    }

}
//slots:
void MainWindow::lauchCalculate(Operation operation){
    /*Read data from UI with preliminary checking*/
    QString arg1 = ui->argLineEdit1->text();
    QString arg2 = ui->argLineEdit2->text();
    if(arg1.isEmpty() || arg2.isEmpty()){
        QMessageBox::critical(this, "error", "Ошибка ввода. Заполните оба поля.");
        return;
    }
    bool valuesIsInt = true;
    int val1 = arg1.toInt(&valuesIsInt);
    int val2 = arg2.toInt(&valuesIsInt);
    if(!valuesIsInt){
        QMessageBox::critical(this, "error", "Ошибка ввода. Калькулятор умеет работать только с целочисленными значениями.");
        return;
    }

    ui->outputListWidget->addItem("Wait for processing complete");
    queueProcessingTaskId.enqueue(ui->outputListWidget->count()-1);


    TaskRequest taskRequest(val1, val2, operation);
    emit calculationRequest(taskRequest);
}


void MainWindow::outputResponse(TaskResponse taskResponse) {
    QString outputStr ="Expression: " % taskResponse.operation % "; "
                        "Status: " % taskResponse.status % "; "
                        "Result: " % taskResponse.result;
    int rowNumber = queueProcessingTaskId.dequeue();
    ui->outputListWidget->item(rowNumber)->setText(outputStr);
}









