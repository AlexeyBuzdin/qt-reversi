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

	// Method for UI configuration, used at constructor phase
	void configureInterface();
	// Refreshes UI gaming field with data taken from fieldStatus
	void refreshField();

	QLabel *lGameBackground;
	QLabel *lGameStatus;

	// Field that shows which turn it is.
	int gameStatus;
	// UI game field
	ClickableLabel ***gamingField;
	// Game field
	int fieldStatus[8][8];

	QImage *whiteImg;
	QImage *blackImg;
	QImage *blankImg;

public slots:
	void cellClicked(int x, int y);

};

#endif // REVERSI_H
