/********************************************************************************
** Form generated from reading UI file 'ellipticfixedsizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELLIPTICFIXEDSIZEDIALOG_H
#define UI_ELLIPTICFIXEDSIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_EllipticFixedSizeDialog
{
public:

    void setupUi(QDialog *EllipticFixedSizeDialog)
    {
        if (EllipticFixedSizeDialog->objectName().isEmpty())
            EllipticFixedSizeDialog->setObjectName(QStringLiteral("EllipticFixedSizeDialog"));
        EllipticFixedSizeDialog->resize(400, 300);

        retranslateUi(EllipticFixedSizeDialog);

        QMetaObject::connectSlotsByName(EllipticFixedSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *EllipticFixedSizeDialog)
    {
        EllipticFixedSizeDialog->setWindowTitle(QApplication::translate("EllipticFixedSizeDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EllipticFixedSizeDialog: public Ui_EllipticFixedSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELLIPTICFIXEDSIZEDIALOG_H
