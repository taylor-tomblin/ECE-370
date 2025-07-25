#include "widget.h"
#include "./ui_widget.h"

void qcolor_print(QColor color, string label) {
    // qDebug() << "QColor object: " << label;
    // qDebug() << "\n    red: " << color.red();
    // qDebug() << "\n    green: " << color.green();
    // qDebug() << "\n    blue: " << color.blue();
    // qDebug() << "\n    alpha: " << color.alpha();

    // qDebug() has additional features cout doesn't

    cout << "QColor object: " << label;
    cout << "\n    red: " << color.red();
    cout << "\n    green: " << color.green();
    cout << "\n    blue: " << color.blue();
    cout << "\n    alpha: " << color.alpha();
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QColor myColor;    // call no-arg constructor

    QColor yourColor (255, 255, 0, 255);    // calling the 4-arg constructor

    qcolor_print(myColor, "myColor");
    qcolor_print(yourColor, "yourColor");

    yourColor.setNamedColor("blue");

    qcolor_print(yourColor, "yourColor");

    // pointer variables
    QColor *ptr;    // itunes!

    // 2 wyas to init
    // 1. set to the address of existing object
    ptr = &myColor;

    qcolor_print(*ptr, "*ptr");

    // 2. use new (similar to malloc)
    ptr = new QColor(0, 255, 0);

    QColor *p;

    p = new QColor(1, 2, 3);

    p->setRgb(0, 127, 25);

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

