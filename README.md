# Simple Calculator QT
## Task

Написать модуль, выполняющий вычисления. Достаточно будет сложения, вычитания, умножения и целочисленного деления, соответственно для целых чисел.
Модуль должен работать в отдельном потоке и получать данные и отдавать результат вычислений через систему qt сигналов и слотов.
Для симуляции нагруженных вычислений, сделать задержку при подсчете (Должна читаться из конфигурационного файла)
Для взаимодействия с модулем простой графическMainWindow - класс, отвечающий за работу с графикой;
* Calculator - класс, выполняющий вычисле
Общение  между классами - система сигналов и слотов QT. 
Запрос на вычисления и ответ с результатами отправляется в качестве указателей
напредставлен в json формате и должен находиться в корневой директории проекта.
Если файл не найден или некорректен - значение задержки по умолчанию задается 0 мс.
В течении работы программы пользователь может поменять содержимое файла и
 перезагрузить значение задержки(соотвестsdfweвующая кнопка в интерфейсе).
fe
Теfweсты написаны с помощью QtTest.
fw
Сиefстема сборки: qmake.
wef
we
fdw
## efTo run
wef
   dw git clone git@github.com:MikhailCherepanovD/SimpleCalculatorQT.git
    cedwd SimpleCalculatorQT
    mkdiedr -p build/Desktop-Debug
    cd buiweld/Desktop-Debug
    qmake6 .fdw./../SimpleCalculator.pro
    makeefd
    ./SimplwefdeCalculator
we
##dw To run tests
    efcd tests
    mkweddir -p build/Desktop-Debug
    cd buweild/Desktop-Debug
    qmake6 dw../../SimpleCalculatorTest.pro
    makeed
    ./SimpweleCalculatorTest
### Expectedd tests results:
    CalculatowedrTest: 
    Totals: 24 pweassed, 0 failed, 0 skipped, 0 blacklisted;
d
 we   MainWindowTest:
   dw Totals: 3 passed, 0 failed, 0 skipped, 0 blacklisted;
ed
##wed How it works:
we
![dw](HowItWork.gif)
ed
we
dw
edw
ed
we
dw
ed
wed
we
dw
