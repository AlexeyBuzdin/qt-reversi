/********************************************************************************
** Form generated from reading UI file 'reversi.ui'
**
** Created: Sun Apr 1 23:26:30 2012
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReversiClass
{
public:

    void setupUi(QWidget *ReversiClass)
    {
        if (ReversiClass->objectName().isEmpty())
            ReversiClass->setObjectName(QString::fromUtf8("ReversiClass"));
        ReversiClass->resize(700, 500);
        ReversiClass->setMinimumSize(QSize(700, 500));
        ReversiClass->setMaximumSize(QSize(700, 500));

        retranslateUi(ReversiClass);

        QMetaObject::connectSlotsByName(ReversiClass);
    } // setupUi

    void retranslateUi(QWidget *ReversiClass)
    {
        ReversiClass->setWindowTitle(QApplication::translate("ReversiClass", "Reversi", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReversiClass: public Ui_ReversiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVERSI_H
