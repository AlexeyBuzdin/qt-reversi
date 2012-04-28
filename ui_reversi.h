/********************************************************************************
** Form generated from reading UI file 'reversi.ui'
**
** Created: Sat Apr 28 20:59:10 2012
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
    QLabel *gameScore;
    QLabel *lscore;

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
        gameScore = new QLabel(ReversiClass);
        gameScore->setObjectName(QString::fromUtf8("gameScore"));
        gameScore->setGeometry(QRect(290, 20, 160, 30));
        lscore = new QLabel(ReversiClass);
        lscore->setObjectName(QString::fromUtf8("lscore"));
        lscore->setGeometry(QRect(330, 10, 41, 17));

        retranslateUi(ReversiClass);

        QMetaObject::connectSlotsByName(ReversiClass);
    } // setupUi

    void retranslateUi(QWidget *ReversiClass)
    {
        ReversiClass->setWindowTitle(QApplication::translate("ReversiClass", "Reversi", 0, QApplication::UnicodeUTF8));
        gameStatus->setText(QApplication::translate("ReversiClass", "Black player's turn", 0, QApplication::UnicodeUTF8));
        gameScore->setText(QString());
        lscore->setText(QApplication::translate("ReversiClass", "Score", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReversiClass: public Ui_ReversiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVERSI_H
