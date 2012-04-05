/********************************************************************************
** Form generated from reading UI file 'reversi.ui'
**
** Created: Fri Apr 6 00:58:44 2012
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
    QLabel *cell00;
    QLabel *cell01;
    QLabel *cell02;
    QLabel *cell03;
    QLabel *cell04;
    QLabel *cell05;
    QLabel *cell06;
    QLabel *cell07;
    QLabel *cell14;
    QLabel *cell12;
    QLabel *cell15;
    QLabel *cell17;
    QLabel *cell11;
    QLabel *cell10;
    QLabel *cell16;
    QLabel *cell13;
    QLabel *cell24;
    QLabel *cell22;
    QLabel *cell25;
    QLabel *cell27;
    QLabel *cell21;
    QLabel *cell20;
    QLabel *cell26;
    QLabel *cell23;
    QLabel *cell34;
    QLabel *cell32;
    QLabel *cell35;
    QLabel *cell37;
    QLabel *cell31;
    QLabel *cell30;
    QLabel *cell36;
    QLabel *cell33;
    QLabel *cell44;
    QLabel *cell42;
    QLabel *cell45;
    QLabel *cell47;
    QLabel *cell41;
    QLabel *cell40;
    QLabel *cell46;
    QLabel *cell43;
    QLabel *cell54;
    QLabel *cell52;
    QLabel *cell55;
    QLabel *cell57;
    QLabel *cell51;
    QLabel *cell50;
    QLabel *cell56;
    QLabel *cell53;
    QLabel *cell64;
    QLabel *cell62;
    QLabel *cell65;
    QLabel *cell67;
    QLabel *cell60;
    QLabel *cell66;
    QLabel *cell63;
    QLabel *cell74;
    QLabel *cell72;
    QLabel *cell75;
    QLabel *cell77;
    QLabel *cell71;
    QLabel *cell70;
    QLabel *cell76;
    QLabel *cell73;
    QLabel *cell61;

    void setupUi(QWidget *ReversiClass)
    {
        if (ReversiClass->objectName().isEmpty())
            ReversiClass->setObjectName(QString::fromUtf8("ReversiClass"));
        ReversiClass->setEnabled(true);
        ReversiClass->resize(495, 530);
        ReversiClass->setMaximumSize(QSize(10000, 10000));
        gameStatus = new QLabel(ReversiClass);
        gameStatus->setObjectName(QString::fromUtf8("gameStatus"));
        gameStatus->setGeometry(QRect(20, 20, 161, 31));
        gameField = new QLabel(ReversiClass);
        gameField->setObjectName(QString::fromUtf8("gameField"));
        gameField->setGeometry(QRect(30, 80, 425, 425));
        gameField->setMinimumSize(QSize(425, 0));
        gameField->setPixmap(QPixmap(QString::fromUtf8("resource/field.png")));
        cell00 = new QLabel(ReversiClass);
        cell00->setObjectName(QString::fromUtf8("cell00"));
        cell00->setGeometry(QRect(30, 80, 51, 51));
        cell01 = new QLabel(ReversiClass);
        cell01->setObjectName(QString::fromUtf8("cell01"));
        cell01->setGeometry(QRect(80, 80, 51, 51));
        cell02 = new QLabel(ReversiClass);
        cell02->setObjectName(QString::fromUtf8("cell02"));
        cell02->setGeometry(QRect(130, 80, 51, 51));
        cell03 = new QLabel(ReversiClass);
        cell03->setObjectName(QString::fromUtf8("cell03"));
        cell03->setGeometry(QRect(180, 80, 51, 51));
        cell04 = new QLabel(ReversiClass);
        cell04->setObjectName(QString::fromUtf8("cell04"));
        cell04->setGeometry(QRect(230, 80, 51, 51));
        cell05 = new QLabel(ReversiClass);
        cell05->setObjectName(QString::fromUtf8("cell05"));
        cell05->setGeometry(QRect(280, 80, 51, 51));
        cell06 = new QLabel(ReversiClass);
        cell06->setObjectName(QString::fromUtf8("cell06"));
        cell06->setGeometry(QRect(330, 80, 51, 51));
        cell07 = new QLabel(ReversiClass);
        cell07->setObjectName(QString::fromUtf8("cell07"));
        cell07->setGeometry(QRect(380, 80, 51, 51));
        cell14 = new QLabel(ReversiClass);
        cell14->setObjectName(QString::fromUtf8("cell14"));
        cell14->setGeometry(QRect(230, 130, 51, 51));
        cell12 = new QLabel(ReversiClass);
        cell12->setObjectName(QString::fromUtf8("cell12"));
        cell12->setGeometry(QRect(130, 130, 51, 51));
        cell15 = new QLabel(ReversiClass);
        cell15->setObjectName(QString::fromUtf8("cell15"));
        cell15->setGeometry(QRect(280, 130, 51, 51));
        cell17 = new QLabel(ReversiClass);
        cell17->setObjectName(QString::fromUtf8("cell17"));
        cell17->setGeometry(QRect(380, 130, 51, 51));
        cell11 = new QLabel(ReversiClass);
        cell11->setObjectName(QString::fromUtf8("cell11"));
        cell11->setGeometry(QRect(80, 130, 51, 51));
        cell10 = new QLabel(ReversiClass);
        cell10->setObjectName(QString::fromUtf8("cell10"));
        cell10->setGeometry(QRect(30, 130, 51, 51));
        cell16 = new QLabel(ReversiClass);
        cell16->setObjectName(QString::fromUtf8("cell16"));
        cell16->setGeometry(QRect(330, 130, 51, 51));
        cell13 = new QLabel(ReversiClass);
        cell13->setObjectName(QString::fromUtf8("cell13"));
        cell13->setGeometry(QRect(180, 130, 51, 51));
        cell24 = new QLabel(ReversiClass);
        cell24->setObjectName(QString::fromUtf8("cell24"));
        cell24->setGeometry(QRect(230, 180, 51, 51));
        cell22 = new QLabel(ReversiClass);
        cell22->setObjectName(QString::fromUtf8("cell22"));
        cell22->setGeometry(QRect(130, 180, 51, 51));
        cell25 = new QLabel(ReversiClass);
        cell25->setObjectName(QString::fromUtf8("cell25"));
        cell25->setGeometry(QRect(280, 180, 51, 51));
        cell27 = new QLabel(ReversiClass);
        cell27->setObjectName(QString::fromUtf8("cell27"));
        cell27->setGeometry(QRect(380, 180, 51, 51));
        cell21 = new QLabel(ReversiClass);
        cell21->setObjectName(QString::fromUtf8("cell21"));
        cell21->setGeometry(QRect(80, 180, 51, 51));
        cell20 = new QLabel(ReversiClass);
        cell20->setObjectName(QString::fromUtf8("cell20"));
        cell20->setGeometry(QRect(30, 180, 51, 51));
        cell26 = new QLabel(ReversiClass);
        cell26->setObjectName(QString::fromUtf8("cell26"));
        cell26->setGeometry(QRect(330, 180, 51, 51));
        cell23 = new QLabel(ReversiClass);
        cell23->setObjectName(QString::fromUtf8("cell23"));
        cell23->setGeometry(QRect(180, 180, 51, 51));
        cell34 = new QLabel(ReversiClass);
        cell34->setObjectName(QString::fromUtf8("cell34"));
        cell34->setGeometry(QRect(230, 230, 51, 51));
        cell32 = new QLabel(ReversiClass);
        cell32->setObjectName(QString::fromUtf8("cell32"));
        cell32->setGeometry(QRect(130, 230, 51, 51));
        cell35 = new QLabel(ReversiClass);
        cell35->setObjectName(QString::fromUtf8("cell35"));
        cell35->setGeometry(QRect(280, 230, 51, 51));
        cell37 = new QLabel(ReversiClass);
        cell37->setObjectName(QString::fromUtf8("cell37"));
        cell37->setGeometry(QRect(380, 230, 51, 51));
        cell31 = new QLabel(ReversiClass);
        cell31->setObjectName(QString::fromUtf8("cell31"));
        cell31->setGeometry(QRect(80, 230, 51, 51));
        cell30 = new QLabel(ReversiClass);
        cell30->setObjectName(QString::fromUtf8("cell30"));
        cell30->setGeometry(QRect(30, 230, 51, 51));
        cell36 = new QLabel(ReversiClass);
        cell36->setObjectName(QString::fromUtf8("cell36"));
        cell36->setGeometry(QRect(330, 230, 51, 51));
        cell33 = new QLabel(ReversiClass);
        cell33->setObjectName(QString::fromUtf8("cell33"));
        cell33->setGeometry(QRect(180, 230, 51, 51));
        cell44 = new QLabel(ReversiClass);
        cell44->setObjectName(QString::fromUtf8("cell44"));
        cell44->setGeometry(QRect(230, 280, 51, 51));
        cell42 = new QLabel(ReversiClass);
        cell42->setObjectName(QString::fromUtf8("cell42"));
        cell42->setGeometry(QRect(130, 280, 51, 51));
        cell45 = new QLabel(ReversiClass);
        cell45->setObjectName(QString::fromUtf8("cell45"));
        cell45->setGeometry(QRect(280, 280, 51, 51));
        cell47 = new QLabel(ReversiClass);
        cell47->setObjectName(QString::fromUtf8("cell47"));
        cell47->setGeometry(QRect(380, 280, 51, 51));
        cell41 = new QLabel(ReversiClass);
        cell41->setObjectName(QString::fromUtf8("cell41"));
        cell41->setGeometry(QRect(80, 280, 51, 51));
        cell40 = new QLabel(ReversiClass);
        cell40->setObjectName(QString::fromUtf8("cell40"));
        cell40->setGeometry(QRect(30, 280, 51, 51));
        cell46 = new QLabel(ReversiClass);
        cell46->setObjectName(QString::fromUtf8("cell46"));
        cell46->setGeometry(QRect(330, 280, 51, 51));
        cell43 = new QLabel(ReversiClass);
        cell43->setObjectName(QString::fromUtf8("cell43"));
        cell43->setGeometry(QRect(180, 280, 51, 51));
        cell54 = new QLabel(ReversiClass);
        cell54->setObjectName(QString::fromUtf8("cell54"));
        cell54->setGeometry(QRect(230, 330, 51, 51));
        cell52 = new QLabel(ReversiClass);
        cell52->setObjectName(QString::fromUtf8("cell52"));
        cell52->setGeometry(QRect(130, 330, 51, 51));
        cell55 = new QLabel(ReversiClass);
        cell55->setObjectName(QString::fromUtf8("cell55"));
        cell55->setGeometry(QRect(280, 330, 51, 51));
        cell57 = new QLabel(ReversiClass);
        cell57->setObjectName(QString::fromUtf8("cell57"));
        cell57->setGeometry(QRect(380, 330, 51, 51));
        cell51 = new QLabel(ReversiClass);
        cell51->setObjectName(QString::fromUtf8("cell51"));
        cell51->setGeometry(QRect(80, 330, 51, 51));
        cell50 = new QLabel(ReversiClass);
        cell50->setObjectName(QString::fromUtf8("cell50"));
        cell50->setGeometry(QRect(30, 330, 51, 51));
        cell56 = new QLabel(ReversiClass);
        cell56->setObjectName(QString::fromUtf8("cell56"));
        cell56->setGeometry(QRect(330, 330, 51, 51));
        cell53 = new QLabel(ReversiClass);
        cell53->setObjectName(QString::fromUtf8("cell53"));
        cell53->setGeometry(QRect(180, 330, 51, 51));
        cell64 = new QLabel(ReversiClass);
        cell64->setObjectName(QString::fromUtf8("cell64"));
        cell64->setGeometry(QRect(230, 380, 51, 51));
        cell62 = new QLabel(ReversiClass);
        cell62->setObjectName(QString::fromUtf8("cell62"));
        cell62->setGeometry(QRect(130, 380, 51, 51));
        cell65 = new QLabel(ReversiClass);
        cell65->setObjectName(QString::fromUtf8("cell65"));
        cell65->setGeometry(QRect(280, 380, 51, 51));
        cell67 = new QLabel(ReversiClass);
        cell67->setObjectName(QString::fromUtf8("cell67"));
        cell67->setGeometry(QRect(380, 380, 51, 51));
        cell60 = new QLabel(ReversiClass);
        cell60->setObjectName(QString::fromUtf8("cell60"));
        cell60->setGeometry(QRect(30, 380, 51, 51));
        cell66 = new QLabel(ReversiClass);
        cell66->setObjectName(QString::fromUtf8("cell66"));
        cell66->setGeometry(QRect(330, 380, 51, 51));
        cell63 = new QLabel(ReversiClass);
        cell63->setObjectName(QString::fromUtf8("cell63"));
        cell63->setGeometry(QRect(180, 380, 51, 51));
        cell74 = new QLabel(ReversiClass);
        cell74->setObjectName(QString::fromUtf8("cell74"));
        cell74->setGeometry(QRect(230, 430, 51, 51));
        cell72 = new QLabel(ReversiClass);
        cell72->setObjectName(QString::fromUtf8("cell72"));
        cell72->setGeometry(QRect(130, 430, 51, 51));
        cell75 = new QLabel(ReversiClass);
        cell75->setObjectName(QString::fromUtf8("cell75"));
        cell75->setGeometry(QRect(280, 430, 51, 51));
        cell77 = new QLabel(ReversiClass);
        cell77->setObjectName(QString::fromUtf8("cell77"));
        cell77->setGeometry(QRect(380, 430, 51, 51));
        cell71 = new QLabel(ReversiClass);
        cell71->setObjectName(QString::fromUtf8("cell71"));
        cell71->setGeometry(QRect(80, 430, 51, 51));
        cell70 = new QLabel(ReversiClass);
        cell70->setObjectName(QString::fromUtf8("cell70"));
        cell70->setGeometry(QRect(30, 430, 51, 51));
        cell76 = new QLabel(ReversiClass);
        cell76->setObjectName(QString::fromUtf8("cell76"));
        cell76->setGeometry(QRect(330, 430, 51, 51));
        cell73 = new QLabel(ReversiClass);
        cell73->setObjectName(QString::fromUtf8("cell73"));
        cell73->setGeometry(QRect(180, 430, 51, 51));
        cell61 = new QLabel(ReversiClass);
        cell61->setObjectName(QString::fromUtf8("cell61"));
        cell61->setGeometry(QRect(80, 380, 51, 51));

        retranslateUi(ReversiClass);

        QMetaObject::connectSlotsByName(ReversiClass);
    } // setupUi

    void retranslateUi(QWidget *ReversiClass)
    {
        ReversiClass->setWindowTitle(QApplication::translate("ReversiClass", "Reversi", 0, QApplication::UnicodeUTF8));
        gameStatus->setText(QApplication::translate("ReversiClass", "It's white players turn", 0, QApplication::UnicodeUTF8));
        gameField->setText(QString());
        cell00->setText(QString());
        cell01->setText(QString());
        cell02->setText(QString());
        cell03->setText(QString());
        cell04->setText(QString());
        cell05->setText(QString());
        cell06->setText(QString());
        cell07->setText(QString());
        cell14->setText(QString());
        cell12->setText(QString());
        cell15->setText(QString());
        cell17->setText(QString());
        cell11->setText(QString());
        cell10->setText(QString());
        cell16->setText(QString());
        cell13->setText(QString());
        cell24->setText(QString());
        cell22->setText(QString());
        cell25->setText(QString());
        cell27->setText(QString());
        cell21->setText(QString());
        cell20->setText(QString());
        cell26->setText(QString());
        cell23->setText(QString());
        cell34->setText(QString());
        cell32->setText(QString());
        cell35->setText(QString());
        cell37->setText(QString());
        cell31->setText(QString());
        cell30->setText(QString());
        cell36->setText(QString());
        cell33->setText(QString());
        cell44->setText(QString());
        cell42->setText(QString());
        cell45->setText(QString());
        cell47->setText(QString());
        cell41->setText(QString());
        cell40->setText(QString());
        cell46->setText(QString());
        cell43->setText(QString());
        cell54->setText(QString());
        cell52->setText(QString());
        cell55->setText(QString());
        cell57->setText(QString());
        cell51->setText(QString());
        cell50->setText(QString());
        cell56->setText(QString());
        cell53->setText(QString());
        cell64->setText(QString());
        cell62->setText(QString());
        cell65->setText(QString());
        cell67->setText(QString());
        cell60->setText(QString());
        cell66->setText(QString());
        cell63->setText(QString());
        cell74->setText(QString());
        cell72->setText(QString());
        cell75->setText(QString());
        cell77->setText(QString());
        cell71->setText(QString());
        cell70->setText(QString());
        cell76->setText(QString());
        cell73->setText(QString());
        cell61->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReversiClass: public Ui_ReversiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVERSI_H
