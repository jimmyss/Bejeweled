/********************************************************************************
** Form generated from reading UI file 'Log.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QLabel *labelName;
    QLabel *labelPassword;
    QPushButton *pushButtonLog;
    QPushButton *pushButtonReg;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditHint;

    void setupUi(QWidget *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QString::fromUtf8("Log"));
        Log->resize(550, 148);
        labelName = new QLabel(Log);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(20, 25, 72, 20));
        labelPassword = new QLabel(Log);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        labelPassword->setGeometry(QRect(20, 60, 72, 21));
        pushButtonLog = new QPushButton(Log);
        pushButtonLog->setObjectName(QString::fromUtf8("pushButtonLog"));
        pushButtonLog->setGeometry(QRect(20, 100, 93, 28));
        pushButtonReg = new QPushButton(Log);
        pushButtonReg->setObjectName(QString::fromUtf8("pushButtonReg"));
        pushButtonReg->setGeometry(QRect(120, 100, 93, 28));
        lineEditName = new QLineEdit(Log);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(120, 20, 401, 31));
        lineEditPassword = new QLineEdit(Log);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(120, 60, 401, 31));
        lineEditHint = new QLineEdit(Log);
        lineEditHint->setObjectName(QString::fromUtf8("lineEditHint"));
        lineEditHint->setGeometry(QRect(220, 100, 301, 31));

        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QWidget *Log)
    {
        Log->setWindowTitle(QCoreApplication::translate("Log", "Log", nullptr));
        labelName->setText(QCoreApplication::translate("Log", "\347\224\250\346\210\267\345\220\215", nullptr));
        labelPassword->setText(QCoreApplication::translate("Log", "\345\257\206\347\240\201", nullptr));
        pushButtonLog->setText(QCoreApplication::translate("Log", "\347\231\273\345\275\225", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("Log", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
