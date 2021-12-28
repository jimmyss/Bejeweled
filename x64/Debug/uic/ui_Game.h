/********************************************************************************
** Form generated from reading UI file 'Game.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButtonFinish;
    QPushButton *pushButtonHint;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(568, 585);
        textEdit = new QTextEdit(Game);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 141, 61));
        pushButtonFinish = new QPushButton(Game);
        pushButtonFinish->setObjectName(QString::fromUtf8("pushButtonFinish"));
        pushButtonFinish->setGeometry(QRect(310, 10, 93, 28));
        pushButtonHint = new QPushButton(Game);
        pushButtonHint->setObjectName(QString::fromUtf8("pushButtonHint"));
        pushButtonHint->setGeometry(QRect(180, 10, 93, 28));

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "QtWidgetsClass", nullptr));
        textEdit->setHtml(QApplication::translate("Game", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\212\266\346\200\201\346\240\217\357\274\237</p></body></html>", nullptr));
        pushButtonFinish->setText(QApplication::translate("Game", "\347\273\223\346\235\237", nullptr));
        pushButtonHint->setText(QApplication::translate("Game", "\346\217\220\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
