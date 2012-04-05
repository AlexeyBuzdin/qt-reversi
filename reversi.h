#ifndef REVERSI_H
#define REVERSI_H

#include <QtGui/QWidget>
#include "ui_reversi.h"

class Reversi : public QWidget
{
    Q_OBJECT

public:
    Reversi(QWidget *parent = 0);
    ~Reversi();

private:
    Ui::ReversiClass ui;
    void configureInterface();
    QLabel *lGameField;
    QLabel *lGameStatus;
    QLabel ***gamingField;

    QImage *white;
    QImage *black;

};

#endif // REVERSI_H
