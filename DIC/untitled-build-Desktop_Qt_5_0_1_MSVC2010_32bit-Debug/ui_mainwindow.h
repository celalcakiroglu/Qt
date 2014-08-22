/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *drPlateButton;
    QPushButton *spButton;
    QPushButton *cleanButton;
    QPushButton *clScrButton;
    QPushButton *closeButton;
    QDoubleSpinBox *denseSpinBox;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *drPlateWithPaintBtn;
    QPushButton *spButton_2;
    QPushButton *cleanButton_2;
    QPushButton *clScrButton_2;
    QPushButton *closeButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(961, 768);
        MainWindow->setWindowOpacity(2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(690, 230, 231, 161));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(550, 560, 93, 141));
        verticalLayout = new QVBoxLayout(horizontalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        drPlateButton = new QPushButton(horizontalLayoutWidget);
        drPlateButton->setObjectName(QStringLiteral("drPlateButton"));

        verticalLayout->addWidget(drPlateButton);

        spButton = new QPushButton(horizontalLayoutWidget);
        spButton->setObjectName(QStringLiteral("spButton"));

        verticalLayout->addWidget(spButton);

        cleanButton = new QPushButton(horizontalLayoutWidget);
        cleanButton->setObjectName(QStringLiteral("cleanButton"));

        verticalLayout->addWidget(cleanButton);

        clScrButton = new QPushButton(horizontalLayoutWidget);
        clScrButton->setObjectName(QStringLiteral("clScrButton"));

        verticalLayout->addWidget(clScrButton);

        closeButton = new QPushButton(horizontalLayoutWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        verticalLayout->addWidget(closeButton);

        denseSpinBox = new QDoubleSpinBox(centralWidget);
        denseSpinBox->setObjectName(QStringLiteral("denseSpinBox"));
        denseSpinBox->setGeometry(QRect(430, 600, 91, 41));
        denseSpinBox->setSingleStep(0.01);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 580, 46, 13));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 650, 46, 13));
        label_3->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(670, 560, 179, 141));
        verticalLayout_2 = new QVBoxLayout(horizontalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        drPlateWithPaintBtn = new QPushButton(horizontalLayoutWidget_2);
        drPlateWithPaintBtn->setObjectName(QStringLiteral("drPlateWithPaintBtn"));

        verticalLayout_2->addWidget(drPlateWithPaintBtn);

        spButton_2 = new QPushButton(horizontalLayoutWidget_2);
        spButton_2->setObjectName(QStringLiteral("spButton_2"));

        verticalLayout_2->addWidget(spButton_2);

        cleanButton_2 = new QPushButton(horizontalLayoutWidget_2);
        cleanButton_2->setObjectName(QStringLiteral("cleanButton_2"));

        verticalLayout_2->addWidget(cleanButton_2);

        clScrButton_2 = new QPushButton(horizontalLayoutWidget_2);
        clScrButton_2->setObjectName(QStringLiteral("clScrButton_2"));

        verticalLayout_2->addWidget(clScrButton_2);

        closeButton_2 = new QPushButton(horizontalLayoutWidget_2);
        closeButton_2->setObjectName(QStringLiteral("closeButton_2"));

        verticalLayout_2->addWidget(closeButton_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 961, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Speckles", 0));
        drPlateButton->setText(QApplication::translate("MainWindow", "Draw the plate", 0));
        spButton->setText(QApplication::translate("MainWindow", "Speckle", 0));
        cleanButton->setText(QApplication::translate("MainWindow", "Clean the plate", 0));
        clScrButton->setText(QApplication::translate("MainWindow", "Clean the screen", 0));
        closeButton->setText(QApplication::translate("MainWindow", "Close", 0));
        label_2->setText(QApplication::translate("MainWindow", "Finer", 0));
        label_3->setText(QApplication::translate("MainWindow", "Coarser", 0));
        drPlateWithPaintBtn->setText(QApplication::translate("MainWindow", "Draw the plate with paintEvent", 0));
        spButton_2->setText(QApplication::translate("MainWindow", "Speckle with paintEvent", 0));
        cleanButton_2->setText(QApplication::translate("MainWindow", "Clean the plate with paintEvent", 0));
        clScrButton_2->setText(QApplication::translate("MainWindow", "Clean the screen of the QGLWidget", 0));
        closeButton_2->setText(QApplication::translate("MainWindow", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
