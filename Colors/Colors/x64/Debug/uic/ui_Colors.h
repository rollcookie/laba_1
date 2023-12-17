/********************************************************************************
** Form generated from reading UI file 'Colors.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORS_H
#define UI_COLORS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorsClass
{
public:

    void setupUi(QWidget *ColorsClass)
    {
        if (ColorsClass->objectName().isEmpty())
            ColorsClass->setObjectName("ColorsClass");
        ColorsClass->resize(600, 400);

        retranslateUi(ColorsClass);

        QMetaObject::connectSlotsByName(ColorsClass);
    } // setupUi

    void retranslateUi(QWidget *ColorsClass)
    {
        ColorsClass->setWindowTitle(QCoreApplication::translate("ColorsClass", "Colors", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorsClass: public Ui_ColorsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORS_H
