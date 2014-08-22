/********************************************************************************
** Form generated from reading UI file 'uniformextension.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIFORMEXTENSION_H
#define UI_UNIFORMEXTENSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_uniformExtension
{
public:

    void setupUi(QDialog *uniformExtension)
    {
        if (uniformExtension->objectName().isEmpty())
            uniformExtension->setObjectName(QStringLiteral("uniformExtension"));
        uniformExtension->resize(400, 300);

        retranslateUi(uniformExtension);

        QMetaObject::connectSlotsByName(uniformExtension);
    } // setupUi

    void retranslateUi(QDialog *uniformExtension)
    {
        uniformExtension->setWindowTitle(QApplication::translate("uniformExtension", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class uniformExtension: public Ui_uniformExtension {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIFORMEXTENSION_H
