/********************************************************************************
** Form generated from reading UI file 'Rank.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rank
{
public:
    QTableView *tableView;

    void setupUi(QWidget *Rank)
    {
        if (Rank->objectName().isEmpty())
            Rank->setObjectName(QString::fromUtf8("Rank"));
        Rank->resize(180, 140);
        Rank->setMinimumSize(QSize(180, 140));
        Rank->setMaximumSize(QSize(180, 140));
        tableView = new QTableView(Rank);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 180, 140));
        tableView->setMinimumSize(QSize(180, 140));
        tableView->setMaximumSize(QSize(180, 140));

        retranslateUi(Rank);

        QMetaObject::connectSlotsByName(Rank);
    } // setupUi

    void retranslateUi(QWidget *Rank)
    {
        Rank->setWindowTitle(QApplication::translate("Rank", "QtWidgetsClass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rank: public Ui_Rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H
