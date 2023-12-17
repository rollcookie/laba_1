#pragma once
#include <QWidget>
#include <string>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QList>
#include <QString>
#include <QPalette>
#include <QColorDialog>

class ColorTab :
    public QWidget
{
    Q_OBJECT
private:
    QPushButton* colorButton;
    QString colorName;
    QColor color;
    int pos;
    double first;
    double second;
    double third;
    double fourth;
    QSpinBox* b1;
    QSpinBox* b2;
    QSpinBox* b3;
    QSpinBox* b4;
public:
    ColorTab(QWidget* parent = nullptr, const QString = "", const int = 0);
    void changeColor();
    void changeColor(double, double, double, double = 0);
    void changeColor(QList<double>);
    QList<double> getColor();
    QList<double> getButtonColor();
    QString getColorName();
    void setBoxColor(double, double, double);
    ~ColorTab();
private slots:
    void onButtonPress();
    void onSlider1(int);
    void onSlider2(int);
    void onSlider3(int);
    void onSlider4(int);
signals:
    void colorChange(int pos, int type);
};

