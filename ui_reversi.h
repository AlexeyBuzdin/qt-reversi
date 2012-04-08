/********************************************************************************
** Form generated from reading UI file 'reversi.ui'
**
** Created: Sun Apr 8 19:32:42 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVERSI_H
#define UI_REVERSI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReversiClass
{
public:
    QLabel *gameStatus;
    QLabel *gameField;

    void setupUi(QWidget *ReversiClass)
    {
        if (ReversiClass->objectName().isEmpty())
            ReversiClass->setObjectName(QString::fromUtf8("ReversiClass"));
        ReversiClass->setEnabled(true);
        ReversiClass->resize(473, 466);
        ReversiClass->setMaximumSize(QSize(10000, 10000));
        gameStatus = new QLabel(ReversiClass);
        gameStatus->setObjectName(QString::fromUtf8("gameStatus"));
        gameStatus->setGeometry(QRect(20, 20, 161, 31));
        gameField = new QLabel(ReversiClass);
        gameField->setObjectName(QString::fromUtf8("gameField"));
        gameField->setGeometry(QRect(30, 50, 425, 425));
        gameField->setMinimumSize(QSize(425, 0));
        gameField->setPixmap(QPixmap(QString::fromUtf8("resource/field.png")));

        retranslateUi(ReversiClass);

        QMetaObject::connectSlotsByName(ReversiClass);
    } // setupUi

    void retranslateUi(QWidget *ReversiClass)
    {
        ReversiClass->setWindowTitle(QApplication::translate("ReversiClass", "Reversi", 0, QApplication::UnicodeUTF8));
        gameStatus->setText(QApplication::translate("ReversiClass", "It's white players turn", 0, QApplication::UnicodeUTF8));
        gameField->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReversiClass: public Ui_ReversiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVERSI_H
