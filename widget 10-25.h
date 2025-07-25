#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QRect>
#include <QColor>
#include <QDebug>

#include <iostream>
#include <string>

#include <QPen>
#include <QBrush>
#include <QPainter>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *evt);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
