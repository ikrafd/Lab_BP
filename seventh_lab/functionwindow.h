#ifndef FUNCTIONWINDOW_H
#define FUNCTIONWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class functionWindow; }
QT_END_NAMESPACE

class functionWindow : public QMainWindow
{
    Q_OBJECT

public:
    functionWindow(QWidget *parent = nullptr);
    ~functionWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::functionWindow *ui;
};
#endif // FUNCTIONWINDOW_H
