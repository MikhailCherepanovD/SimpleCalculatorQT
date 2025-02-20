/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *resultLabel;
    QListWidget *outputListWidget;
    QLabel *inputLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *arglabel1;
    QLineEdit *argLineEdit1;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *argLabel2;
    QLineEdit *argLineEdit2;
    QPushButton *subtractPushButton;
    QPushButton *addPushButton;
    QPushButton *dividePushButton;
    QPushButton *multiplyPushButton;
    QPushButton *reloadPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(542, 343);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(190, 10, 341, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        resultLabel = new QLabel(verticalLayoutWidget);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel);

        outputListWidget = new QListWidget(verticalLayoutWidget);
        outputListWidget->setObjectName("outputListWidget");

        verticalLayout->addWidget(outputListWidget);

        inputLabel = new QLabel(centralwidget);
        inputLabel->setObjectName("inputLabel");
        inputLabel->setGeometry(QRect(40, 10, 121, 18));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 40, 151, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        arglabel1 = new QLabel(horizontalLayoutWidget);
        arglabel1->setObjectName("arglabel1");

        horizontalLayout->addWidget(arglabel1);

        argLineEdit1 = new QLineEdit(horizontalLayoutWidget);
        argLineEdit1->setObjectName("argLineEdit1");

        horizontalLayout->addWidget(argLineEdit1);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(30, 80, 151, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        argLabel2 = new QLabel(horizontalLayoutWidget_2);
        argLabel2->setObjectName("argLabel2");

        horizontalLayout_2->addWidget(argLabel2);

        argLineEdit2 = new QLineEdit(horizontalLayoutWidget_2);
        argLineEdit2->setObjectName("argLineEdit2");

        horizontalLayout_2->addWidget(argLineEdit2);

        subtractPushButton = new QPushButton(centralwidget);
        subtractPushButton->setObjectName("subtractPushButton");
        subtractPushButton->setGeometry(QRect(110, 120, 71, 61));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(subtractPushButton->sizePolicy().hasHeightForWidth());
        subtractPushButton->setSizePolicy(sizePolicy);
        addPushButton = new QPushButton(centralwidget);
        addPushButton->setObjectName("addPushButton");
        addPushButton->setGeometry(QRect(30, 120, 71, 61));
        dividePushButton = new QPushButton(centralwidget);
        dividePushButton->setObjectName("dividePushButton");
        dividePushButton->setGeometry(QRect(110, 190, 71, 61));
        multiplyPushButton = new QPushButton(centralwidget);
        multiplyPushButton->setObjectName("multiplyPushButton");
        multiplyPushButton->setGeometry(QRect(30, 190, 71, 61));
        reloadPushButton = new QPushButton(centralwidget);
        reloadPushButton->setObjectName("reloadPushButton");
        reloadPushButton->setGeometry(QRect(30, 260, 151, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 542, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "Calculation result:", nullptr));
        inputLabel->setText(QCoreApplication::translate("MainWindow", "Input numbers:", nullptr));
        arglabel1->setText(QCoreApplication::translate("MainWindow", "arg1:", nullptr));
        argLabel2->setText(QCoreApplication::translate("MainWindow", "arg2:", nullptr));
        subtractPushButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        addPushButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        dividePushButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        multiplyPushButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        reloadPushButton->setText(QCoreApplication::translate("MainWindow", "Reload delay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
