/********************************************************************************
** Form generated from reading UI file 'xxlProject.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XXLPROJECT_H
#define UI_XXLPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XXLProjectClass
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonHelp;
    QPushButton *pushButtonRank;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *XXLProjectClass)
    {
        if (XXLProjectClass->objectName().isEmpty())
            XXLProjectClass->setObjectName(QString::fromUtf8("XXLProjectClass"));
        XXLProjectClass->resize(510, 380);
        XXLProjectClass->setMinimumSize(QSize(510, 380));
        XXLProjectClass->setMaximumSize(QSize(510, 380));
        centralwidget = new QWidget(XXLProjectClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(170, 170, 160, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonStart = new QPushButton(verticalLayoutWidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        verticalLayout->addWidget(pushButtonStart);

        pushButtonHelp = new QPushButton(verticalLayoutWidget);
        pushButtonHelp->setObjectName(QString::fromUtf8("pushButtonHelp"));

        verticalLayout->addWidget(pushButtonHelp);

        pushButtonRank = new QPushButton(verticalLayoutWidget);
        pushButtonRank->setObjectName(QString::fromUtf8("pushButtonRank"));

        verticalLayout->addWidget(pushButtonRank);

        XXLProjectClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(XXLProjectClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 18));
        XXLProjectClass->setMenuBar(menubar);
        statusbar = new QStatusBar(XXLProjectClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        XXLProjectClass->setStatusBar(statusbar);

        retranslateUi(XXLProjectClass);

        QMetaObject::connectSlotsByName(XXLProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *XXLProjectClass)
    {
        XXLProjectClass->setWindowTitle(QApplication::translate("XXLProjectClass", "MainWindow", nullptr));
        pushButtonStart->setText(QApplication::translate("XXLProjectClass", "\345\274\200\345\247\213", nullptr));
        pushButtonHelp->setText(QApplication::translate("XXLProjectClass", "\345\270\256\345\212\251", nullptr));
        pushButtonRank->setText(QApplication::translate("XXLProjectClass", "\346\216\222\350\241\214\346\246\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XXLProjectClass: public Ui_XXLProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XXLPROJECT_H
