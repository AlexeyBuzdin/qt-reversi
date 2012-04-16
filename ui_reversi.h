/********************************************************************************
** Form generated from reading UI file 'reversi.ui'
**
** Created: Sat Apr 14 00:46:11 2012
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
    QLabel *gameScore;

    void setupUi(QWidget *ReversiClass)
    {
        if (ReversiClass->objectName().isEmpty())
            ReversiClass->setObjectName(QString::fromUtf8("ReversiClass"));
        ReversiClass->setEnabled(true);
        ReversiClass->resize(474, 466);
        ReversiClass->setMaximumSize(QSize(10000, 10000));
        gameStatus = new QLabel(ReversiClass);
        gameStatus->setObjectName(QString::fromUtf8("gameStatus"));
        gameStatus->setGeometry(QRect(20, 20, 160, 30));
        gameField = new QLabel(ReversiClass);
        gameField->setObjectName(QString::fromUtf8("gameField"));
        gameField->setGeometry(QRect(30, 40, 425, 425));
        gameField->setMinimumSize(QSize(425, 0));
        gameField->setPixmap(QPixmap(QString::fromUtf8("resource/field.png")));
        gameScore = new QLabel(ReversiClass);
        gameScore->setObjectName(QString::fromUtf8("gameScore"));
        gameScore->setGeometry(QRect(250, 20, 160, 30));

        retranslateUi(ReversiClass);

        QMetaObject::connectSlotsByName(ReversiClass);
    } // setupUi

    void retranslateUi(QWidget *ReversiClass)
    {
        ReversiClass->setWindowTitle(QApplication::translate("ReversiClass", "Reversi", 0, QApplication::UnicodeUTF8));
        gameStatus->setText(QApplication::translate("ReversiClass", "It's black player's turn", 0, QApplication::UnicodeUTF8));
        gameField->setText(QString());
        gameScore->setText(QApplication::translate("ReversiClass", "Score:    2:2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReversiClass: public Ui_ReversiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVERSI_H
