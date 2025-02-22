#include "../include/mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Simple Calculator");
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

    calculationThread->quit();
    calculationThread->wait();
    delete calculationThread;
}
//slots:
void MainWindow::lauchCalculate(Operation operation){
    /*Read data from UI with preliminary checking*/
    QString arg1 = ui->argLineEdit1->text();
    QString arg2 = ui->argLineEdit2->text();
    if(arg1.isEmpty() || arg2.isEmpty()){
        QMessageBox::critical(this, "Input error", "Fill in both fields");
        return;
    }
    bool valuesIsInt = true;
    int val1 = arg1.toInt(&valuesIsInt);
    int val2 = arg2.toInt(&valuesIsInt);
    if(!valuesIsInt){
        QMessageBox::critical(this, "Input error", "Only numeric data is allowed.");
        return;
    }

    ui->outputListWidget->addItem("Wait for processing complete");
    queueProcessingTaskId.enqueue(ui->outputListWidget->count()-1);


    auto taskRequestPtr = QSharedPointer<TaskRequest>::create(val1, val2, operation);

    emit calculationRequest(taskRequestPtr);
}


void MainWindow::outputResponse(QSharedPointer<TaskResponse> taskResponsePtr) {
    QString outputStr ="Expression: " % taskResponsePtr->operation % "; "
                        "Status: " % taskResponsePtr->status % "; "
                        "Result: " % taskResponsePtr->result;
    int rowNumber = queueProcessingTaskId.dequeue();
    ui->outputListWidget->item(rowNumber)->setText(outputStr);
}









