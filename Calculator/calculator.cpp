#include "calculator.h"
#include "ui_calculator.h"

#include <QLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>

calculator::calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
    resize(400, 40);
    move(500, 300);
    QWidget *parent1 = new QWidget;
    layout = new QHBoxLayout(this);
    first = new QSpinBox(this);
    operation = new QComboBox(this);
    second = new QSpinBox(this);
    result = new QLabel(this);
    equal = new QLabel(this);

    first->setMaximum(999);
    first->setMinimum(-999);

    second->setMaximum(999);
    second->setMinimum(-999);

    result->setNum(0);
    result->setStyleSheet("QLabel {background-color : white}");
    result->setMaximumHeight(25);

    equal->setText("=");
    equal->setMaximumWidth(10);

    operation->addItem("+", 0);
    operation->addItem("-", 1);
    operation->addItem("*", 2);

    layout->addWidget(first);
    layout->addWidget(operation);
    layout->addWidget(second);
    layout->addWidget(equal);
    layout->addWidget(result);

    parent1->setLayout(layout);

    connect(operation, SIGNAL(activated(QString)), this, SLOT(calculate(QString)));
    connect(first, SIGNAL(valueChanged(int)), this, SLOT(update()));
    connect(second, SIGNAL(valueChanged(int)), this, SLOT(update()));


}
calculator::~calculator()
{
    delete ui;
}
void calculator::calculate(QString string) {
    if(string == "+"){
        result->setNum(first->value() + second->value());
    }
    if(string == "-"){
        result->setNum(first->value() - second->value());
    }
    if(string == "*"){
        result->setNum(first->value() * second->value()) ;
    }
}

void calculator::update() {
    if(operation->currentIndex()== 0){
        result->setNum(first->value() + second->value());
    }
    if(operation->currentIndex()== 1){
        result->setNum(first->value()- second->value());
    }
    if(operation->currentIndex()==2){
        result->setNum(first->value() * second->value());
    }
}
