/********************************************************************************
** Form generated from reading UI file 'Rank.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rank
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *Rank)
    {
        if (Rank->objectName().isEmpty())
            Rank->setObjectName(QString::fromUtf8("Rank"));
        Rank->resize(400, 300);
        textEdit = new QTextEdit(Rank);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(130, 90, 104, 87));

        retranslateUi(Rank);

        QMetaObject::connectSlotsByName(Rank);
    } // setupUi

    void retranslateUi(QWidget *Rank)
    {
        Rank->setWindowTitle(QCoreApplication::translate("Rank", "QtWidgetsClass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rank: public Ui_Rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H
