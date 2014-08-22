/********************************************************************************
** Form generated from reading UI file 'speckles.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECKLES_H
#define UI_SPECKLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_speckles
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *speckles)
    {
        if (speckles->objectName().isEmpty())
            speckles->setObjectName(QStringLiteral("speckles"));
        speckles->resize(627, 327);
        speckles->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(speckles);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(speckles);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);

        verticalLayout->addWidget(graphicsView);


        retranslateUi(speckles);

        QMetaObject::connectSlotsByName(speckles);
    } // setupUi

    void retranslateUi(QDialog *speckles)
    {
        speckles->setWindowTitle(QApplication::translate("speckles", "speckles", 0));
    } // retranslateUi

};

namespace Ui {
    class speckles: public Ui_speckles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECKLES_H
