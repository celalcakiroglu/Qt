/********************************************************************************
** Form generated from reading UI file 'ellipticfixedsize.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELLIPTICFIXEDSIZE_H
#define UI_ELLIPTICFIXEDSIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_EllipticFixedSize
{
public:

    void setupUi(QDialog *EllipticFixedSize)
    {
        if (EllipticFixedSize->objectName().isEmpty())
            EllipticFixedSize->setObjectName(QStringLiteral("EllipticFixedSize"));
        EllipticFixedSize->resize(400, 300);

        retranslateUi(EllipticFixedSize);

        QMetaObject::connectSlotsByName(EllipticFixedSize);
    } // setupUi

    void retranslateUi(QDialog *EllipticFixedSize)
    {
        EllipticFixedSize->setWindowTitle(QApplication::translate("EllipticFixedSize", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EllipticFixedSize: public Ui_EllipticFixedSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELLIPTICFIXEDSIZE_H
