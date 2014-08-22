/********************************************************************************
** Form generated from reading UI file 'rigidbodytranslation.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGIDBODYTRANSLATION_H
#define UI_RIGIDBODYTRANSLATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_rigidBodyTranslation
{
public:

    void setupUi(QDialog *rigidBodyTranslation)
    {
        if (rigidBodyTranslation->objectName().isEmpty())
            rigidBodyTranslation->setObjectName(QStringLiteral("rigidBodyTranslation"));
        rigidBodyTranslation->resize(400, 300);

        retranslateUi(rigidBodyTranslation);

        QMetaObject::connectSlotsByName(rigidBodyTranslation);
    } // setupUi

    void retranslateUi(QDialog *rigidBodyTranslation)
    {
        rigidBodyTranslation->setWindowTitle(QApplication::translate("rigidBodyTranslation", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class rigidBodyTranslation: public Ui_rigidBodyTranslation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGIDBODYTRANSLATION_H
