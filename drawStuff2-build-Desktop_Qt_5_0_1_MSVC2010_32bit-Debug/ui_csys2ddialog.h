/********************************************************************************
** Form generated from reading UI file 'csys2ddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSYS2DDIALOG_H
#define UI_CSYS2DDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_csys2Ddialog
{
public:

    void setupUi(QDialog *csys2Ddialog)
    {
        if (csys2Ddialog->objectName().isEmpty())
            csys2Ddialog->setObjectName(QStringLiteral("csys2Ddialog"));
        csys2Ddialog->resize(400, 300);

        retranslateUi(csys2Ddialog);

        QMetaObject::connectSlotsByName(csys2Ddialog);
    } // setupUi

    void retranslateUi(QDialog *csys2Ddialog)
    {
        csys2Ddialog->setWindowTitle(QApplication::translate("csys2Ddialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class csys2Ddialog: public Ui_csys2Ddialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSYS2DDIALOG_H
