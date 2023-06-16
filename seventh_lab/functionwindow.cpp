#include "functionwindow.h"
#include "./ui_functionwindow.h"
#include "function.h"
#include <QMessageBox>

functionWindow::functionWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::functionWindow)
{
    ui->setupUi(this);
}

functionWindow::~functionWindow()
{
    delete ui;
}


void functionWindow::on_pushButton_clicked()
{
    QString fResult = "Перший результат: ";
    QString sResult = "Другий результат: ";
    QString firstInput = ui->valueOne->text();
    QString secondInput = ui->valueSecond->text();

    try {
        bool ok1, ok2;
        float firstArg = firstInput.toFloat(&ok1);
        float secondArg = secondInput.toFloat(&ok2);

        if (!ok1 || !ok2) {
            throw invalid_argument("Невірний формат введення");
        }

        functionLog first(firstArg), second(secondArg);
        float result1 = first.calculate();
        float result2 = second.calculate();
        QString firstResult = fResult + QString::number(result1);
        ui->firstResult->setText(firstResult);
        QString secondResult = sResult+ QString::number(result2);
        ui->secondResult->setText(secondResult);

        if (result1 > result2) {
            ui->compare->setText("Значення функції для першого аргументу більше");
        } else  if (result1 < result2){
            ui->compare->setText("Значення функції для другого аргументу більше");
        } else{
            ui->compare->setText("Значення функції для обох аргументів рівні");
        }
    } catch (const std::exception& ex) {
        ui->compare->setText("");
        ui->firstResult->setText(fResult);
        ui->secondResult->setText(sResult);
        QMessageBox::critical(this, "Error", ex.what());
    }
}
