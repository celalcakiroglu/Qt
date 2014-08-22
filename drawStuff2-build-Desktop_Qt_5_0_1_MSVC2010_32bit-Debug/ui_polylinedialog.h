/********************************************************************************
** Form generated from reading UI file 'polylinedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLYLINEDIALOG_H
#define UI_POLYLINEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_PolyLineDialog
{
public:

    void setupUi(QDialog *PolyLineDialog)
    {
        if (PolyLineDialog->objectName().isEmpty())
            PolyLineDialog->setObjectName(QStringLiteral("PolyLineDialog"));
        PolyLineDialog->resize(400, 300);

        retranslateUi(PolyLineDialog);

        QMetaObject::connectSlotsByName(PolyLineDialog);
    } // setupUi

    void retranslateUi(QDialog *PolyLineDialog)
    {
        PolyLineDialog->setWindowTitle(QApplication::translate("PolyLineDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PolyLineDialog: public Ui_PolyLineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLYLINEDIALOG_H
