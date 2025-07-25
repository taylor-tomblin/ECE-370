#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myLabel = new QLabel("My Application");
    sliderLabel = new QLabel("My Slider");

    QPushButton *myButton = new QPushButton("Submit",this);
    QSlider *mySlider = new QSlider();

    mySlider->setOrientation(Qt::Horizontal);

    QVBoxLayout *myLayout = new QVBoxLayout(this);

    this->setLayout(myLayout);

    myLayout->addWidget(myLabel);
    myLayout->addWidget(myButton);
    myLayout->addWidget(mySlider);
    myLayout->addWidget(sliderLabel);

    connect(myButton, &QPushButton::clicked, this, &Widget::onClick);
    connect(mySlider, &QSlider::sliderMoved, this, &Widget::onSlide);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onClick() {
    qDebug() << "Button clicked!";

    myLabel->setText("Button Clicked!");
}

void Widget::onSlide() {
    qDebug() << "Slider moved!";

    int pos = mySlider->sliderPosition();
    string str = "value: " + to_string(pos);

    sliderLabel->setText(str.c_str());
}
