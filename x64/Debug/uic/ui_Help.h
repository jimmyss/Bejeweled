/********************************************************************************
** Form generated from reading UI file 'Help.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QLabel *label;
    QTextBrowser *helpText;

    void setupUi(QWidget *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QString::fromUtf8("Help"));
        Help->resize(537, 376);
        label = new QLabel(Help);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 20, 81, 21));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        helpText = new QTextBrowser(Help);
        helpText->setObjectName(QString::fromUtf8("helpText"));
        helpText->setGeometry(QRect(60, 60, 411, 271));

        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QWidget *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "QtWidgetsClass", nullptr));
        label->setText(QApplication::translate("Help", "\345\270\256\345\212\251", nullptr));
        helpText->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:16pt; font-weight:600;\">1.\302\240\347\274\226\345\206\231\347\233\256\347\232\204</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:600;\">    \346\234\254\346\226\207\346\241\243\344\275\234\344\270\272\351\241\271\347\233\256\347\232\204\347\224\250\346\210\267\346\211\213\345\206\214\357\274\214\345\260\206\345\257\271\345\274\200"
                        "\345\277\203\346\266\210\346\266\210\344\271\220\347\232\204\344\275\277\347\224\250\357\274\214\346\223\215\344\275\234\344\273\245\345\217\212\347\273\264\346\212\244\350\277\233\350\241\214\346\217\217\350\277\260\357\274\214\344\275\277\347\224\250\346\210\267\350\203\275\345\244\237\351\200\232\350\277\207\346\234\254\346\211\213\345\206\214\344\272\206\350\247\243\346\234\254\346\270\270\346\210\217\347\232\204\345\237\272\346\234\254\346\223\215\344\275\234\345\217\212\350\247\204\345\210\231\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:16pt; font-weight:600;\">2.\302\240\346\270\270\346\210\217\344\273\213\347\273\215</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:"
                        "600;\">    \350\257\245\346\270\270\346\210\217\345\261\236\344\272\216\346\225\217\346\215\267\347\261\273\346\270\270\346\210\217\357\274\214\350\200\203\351\252\214\346\270\270\346\210\217\347\216\251\345\256\266\347\232\204\345\217\215\345\272\224\351\200\237\345\272\246\344\273\245\345\217\212\350\247\202\345\257\237\350\203\275\345\212\233\357\274\214\346\211\213\347\234\274\345\215\217\350\260\203\344\270\200\350\207\264\347\232\204\350\203\275\345\212\233\343\200\202\345\271\266\344\270\272\347\224\250\346\210\267\346\217\220\344\276\233\351\227\262\346\232\207\345\250\261\344\271\220\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:16pt; font-weight:600;\">3.\302\240\344\275\277\347\224\250\350\257\264\346\230\216</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-in"
                        "dent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:600;\">    \347\224\250\346\210\267\351\246\226\345\205\210\351\234\200\350\246\201\346\263\250\345\206\214\350\264\246\345\217\267\357\274\214\347\204\266\345\220\216\347\231\273\345\275\225\346\270\270\346\210\217\343\200\202\347\202\271\345\207\273\342\200\234\345\274\200\345\247\213\346\270\270\346\210\217\342\200\235\345\215\263\345\217\257\350\277\233\345\205\245\346\270\270\346\210\217\343\200\202\347\202\271\345\207\273\342\200\234\346\216\222\350\241\214\346\246\234\342\200\235\345\217\257\346\237\245\347\234\213\350\207\252\345\267\261\346\270\270\346\210\217\350\256\260\345\275\225\346\216\222\345\220\215\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:16pt; font-weight:600;\">4.\302\240\346\270\270\346\210\217\350\247\204\345\210\231</span><"
                        "/p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:600;\">\347\202\271\345\207\273\344\270\244\344\270\252\344\270\215\345\220\214\347\232\204\346\226\271\345\235\227\357\274\214\350\213\245\344\273\226\344\273\254\344\272\244\346\215\242\344\271\213\345\220\216\357\274\214\350\203\275\344\272\247\347\224\237\344\270\211\344\270\252\347\233\270\345\220\214\347\232\204\350\211\262\345\235\227\346\210\220\345\220\214\344\270\200\347\233\264\347\272\277\357\274\210\346\250\252\347\253\226\351\203\275\345\217\257\357\274\211\345\260\261\345\217\257\344\273\245\346\266\210\351\231\244\343\200\202\346\257\217\344\270\200\346\254\241\346\270\270\346\210\217\344\270\255\344\273\245\344\272\244\346\215\242\346\255\245\346\225\260\350\256\241\345\210\206\343\200\202</span></p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:1"
                        "2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:600;\">\302\240</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
