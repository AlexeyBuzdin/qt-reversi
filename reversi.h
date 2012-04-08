#ifndef REVERSI_H
#define REVERSI_H

#include <QtGui/QWidget>
#include "ui_reversi.h"
#include "src/ClickableLabel.h"
class Reversi: public QWidget {
Q_OBJECT

public:
	Reversi(QWidget *parent = 0);
	~Reversi();

private:
	Ui::ReversiClass ui;
	void configureInterface();
	void changeField();
	void turn(int x, int y, int turn);

	QLabel *lGameField;
	QLabel *lGameStatus;
	ClickableLabel ***gamingField;
	int fieldStatus[8][8];

	QImage *whiteImg;
	QImage *blackImg;
	QImage *blankImg;

};

#endif // REVERSI_H
