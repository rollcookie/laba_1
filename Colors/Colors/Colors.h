#pragma once

#include <QtWidgets/QWidget>
#include "ui_Colors.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPUshButton>
#include <QColor>
#include "ColorTab.h"
#include <qcombobox.h>

class Colors : public QWidget
{
    Q_OBJECT

public:
    Colors(QWidget *parent = nullptr);
    ~Colors();
    void setupTabs(QList<QString> colors);
private:
    Ui::ColorsClass ui;
    QList<ColorTab*> tabs;
    QComboBox* comboBox;
    QVBoxLayout* vl;
    QHBoxLayout* hl1;
    QHBoxLayout* hl2;
private slots:
    void processColorChange(int pos, int type);
    void onVariantChange(int);
};
