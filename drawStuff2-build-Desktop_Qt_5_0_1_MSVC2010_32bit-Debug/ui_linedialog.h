/********************************************************************************
** Form generated from reading UI file 'linedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEDIALOG_H
#define UI_LINEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_LineDialog
{
public:

    void setupUi(QDialog *LineDialog)
    {
        if (LineDialog->objectName().isEmpty())
            LineDialog->setObjectName(QStringLiteral("LineDialog"));
        LineDialog->resize(400, 300);

        retranslateUi(LineDialog);

        QMetaObject::connectSlotsByName(LineDialog);
    } // setupUi

    void retranslateUi(QDialog *LineDialog)
    {
        LineDialog->setWindowTitle(QApplication::translate("LineDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class LineDialog: public Ui_LineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEDIALOG_H
