# Simple Calculator QT

## To run

    git clone git@github.com:MikhailCherepanovD/SimpleCalculatorQT.git
    cd SimpleCalculatorQT
    mkdir -p build/Desktop-Debug
    cd build/Desktop-Debug
    qmake6 ../../SimpleCalculator.pro
    make
    ./SimpleCalculator

## To run tests
    cd tests
    mkdir -p build/Desktop-Debug
    cd build/Desktop-Debug
    qmake6 ../../SimpleCalculatorTest.pro
    make
    ./SimpleCalculatorTest
### Expected tests results:
    CalculatorTest: 
    Totals: 24 passed, 0 failed, 0 skipped, 0 blacklisted;

    MainWindowTest:
    Totals: 3 passed, 0 failed, 0 skipped, 0 blacklisted;

## How it works:

![](HowItWork.gif)
