#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>

namespace Ui {
class calculator;
}

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();

private:
    Ui::calculator *ui;
    QLabel *result;
    QSpinBox *first;
    QSpinBox *second;
    QComboBox *operation;
    QLabel *equal;
    QHBoxLayout *layout;

private slots:
    void calculate(QString string);
    void update();
};

#endif // CALCULATOR_H
