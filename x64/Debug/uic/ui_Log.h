/********************************************************************************
** Form generated from reading UI file 'Log.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
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
    QLabel *labelPassword;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonLog;
    QPushButton *pushButtonReg;
    QLabel *labelName;
    QLineEdit *lineEditHint;

    void setupUi(QWidget *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QString::fromUtf8("Log"));
        Log->resize(510, 380);
        Log->setMinimumSize(QSize(510, 380));
        Log->setMaximumSize(QSize(510, 380));
        labelPassword = new QLabel(Log);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        labelPassword->setGeometry(QRect(110, 250, 72, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        labelPassword->setFont(font);
        lineEditName = new QLineEdit(Log);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(190, 195, 190, 31));
        lineEditPassword = new QLineEdit(Log);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(190, 245, 190, 31));
        pushButtonLog = new QPushButton(Log);
        pushButtonLog->setObjectName(QString::fromUtf8("pushButtonLog"));
        pushButtonLog->setGeometry(QRect(100, 300, 93, 40));
        pushButtonReg = new QPushButton(Log);
        pushButtonReg->setObjectName(QString::fromUtf8("pushButtonReg"));
        pushButtonReg->setGeometry(QRect(200, 300, 93, 40));
        labelName = new QLabel(Log);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(110, 200, 72, 20));
        labelName->setFont(font);
        lineEditHint = new QLineEdit(Log);
        lineEditHint->setObjectName(QString::fromUtf8("lineEditHint"));
        lineEditHint->setGeometry(QRect(300, 300, 91, 41));

        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QWidget *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "Log", nullptr));
        labelPassword->setText(QApplication::translate("Log", "\345\257\206\347\240\201", nullptr));
        pushButtonLog->setText(QApplication::translate("Log", "\347\231\273\345\275\225", nullptr));
        pushButtonReg->setText(QApplication::translate("Log", "\346\263\250\345\206\214", nullptr));
        labelName->setText(QApplication::translate("Log", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
