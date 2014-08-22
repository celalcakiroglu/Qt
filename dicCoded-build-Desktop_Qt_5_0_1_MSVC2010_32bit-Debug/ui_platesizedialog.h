/********************************************************************************
** Form generated from reading UI file 'platesizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLATESIZEDIALOG_H
#define UI_PLATESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_PlateSizeDialog
{
public:

    void setupUi(QDialog *PlateSizeDialog)
    {
        if (PlateSizeDialog->objectName().isEmpty())
            PlateSizeDialog->setObjectName(QStringLiteral("PlateSizeDialog"));
        PlateSizeDialog->resize(400, 300);

        retranslateUi(PlateSizeDialog);

        QMetaObject::connectSlotsByName(PlateSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *PlateSizeDialog)
    {
        PlateSizeDialog->setWindowTitle(QApplication::translate("PlateSizeDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PlateSizeDialog: public Ui_PlateSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLATESIZEDIALOG_H
