#include "widget.h"
#include "./ui_widget.h"

void qrect_print(QRect rect, string label) {
    cout << "\n\nQRect Object: " << label << "-------------";

    cout << "\n         x: " << rect.x();
    cout << "\n         y: " << rect.y();
    cout << "\n     width: " << rect.width();
    cout << "\n    height: " << rect.height();
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // Regular variable (object)
    QRect rect;    // calling the no-arg constructor

    qDebug() << "rect: " << rect;

    rect.setRect(10, 10, 30, 20);

    qDebug() << "rect: " << rect;

    QRect r(100, 200, 300, 300);    // calls 4-arg constructor

    qDebug() << "r: " << r;

    QRect rectangles[10];    // calls the no-arg constructor for 10 rectangles, allocated to the stack

    for (int i = 0; i < 10; i++) {
        rectangles[i].setRect(rand() % 1000, rand() % 1000, 100, 100);

        qrect_print(rectangles[i], "rectangles [" + to_string(i) + "]");
    }

    // Pointer variables
    QRect *ptr;    // itunes!

    // Init ptr... way 1:
    ptr = &rect;

    qDebug() << "ptr: " << ptr;
    \
    qrect_print(*ptr, "*ptr");

    // Init ptr... way 2:
    ptr = new QRect(1, 2, 3, 4);

    delete ptr;

    //ptr->setX(10);     Problem: undefined behavior

    ptr = nullptr;

    ptr = new QRect;
    ptr = new QRect();

    // Create a dynamic array
    int n = 20;

    QRect *p;

    p = new QRect[10];    // calls no-arg, allocates to heap
                          // heap can survive function calls, stack does not exist out of the function

    delete[] p;    // deletes

    ptr->setRect(10, 20, 30, 40);

    QRect r1(10, 10, 10, 10);
    QRect r2(0, 0, 5, 5);

    bool k;

    k = r1.intersects(r2);

    qDebug() << "k: " << k;
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *evt) {
    QPainter p(this);

    QColor penColor(0, 0, 0);
    QColor brushColor(255, 255, 0);

    QPen myPen(penColor);

    myPen.setWidth(5);

    QBrush myBrush(brushColor);

    QColor c1(255, 255, 0);
    QColor c2(0, 255, 255);
    QColor c_overlap(255, 0, 0);


    QRect r1(100, 200, 100, 100);
    QRect r2(50, 250, 100, 100);
    QRect r_overlap;

    p.setPen(myPen);
    p.setBrush(myBrush);

    myBrush.setColor(c1);
    p.drawRect(r1);

    myBrush.setColor(c2);
    p.drawRect(r2);

    r_overlap = r1.intersected(r2);

    myBrush.setColor(c_overlap);
    p.setBrush(myBrush);
    p.drawRect(r_overlap);
}
