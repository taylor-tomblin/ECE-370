#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel myLabel("My Application");
    QPushButton myButton("Submit", this);

    QVBoxLayout myLayout(this);

    this->setLayout(&myLayout);

    myLayout.addWidget(&myLabel);
    myLayout.addWidget(&myButton);
}

Widget::~Widget()
{
    delete ui;
}

