#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QSlider>

#include <iostream>
#include <string>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QLabel *myLabel;
    QLabel *sliderLabel;

    QSlider *mySlider;

public slots:
    void onClick();    // Event handler for our QPushButton
    void onSlide();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
