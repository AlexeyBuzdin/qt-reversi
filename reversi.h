#ifndef REVERSI_H
#define REVERSI_H

#include <QtGui/QWidget>
#include "ui_reversi.h"
#include "src/ClickableLabel.h"
#include "src/Lines.h"
#include "src/Point.h"


class Reversi: public QWidget {
Q_OBJECT

public:
	Reversi(QWidget *parent = 0);
	~Reversi();

private:
	Ui::ReversiClass ui;

	// Refreshes the gaming score
	void calculateScore();
	// Returns true if player can not make a legal turn
	bool thereIsNoLegalTurns();
	// Change player turn or ends the game if skippedTurns is 2
	void changePlayer(int skippedTurns);
	// Method for UI configuration, used at constructor phase
	void configureInterface();
	// Refreshes UI gaming field with data taken from fieldStatus
	void refreshField();

	QLabel *lGameStatus;
	QLabel *lGameScore;

	// Field that shows which turn it is.
	int gameStatus;
	// UI game field
	ClickableLabel ***gamingField;
	// Game field
	int **fieldStatus;

	QImage *whiteImg;
	QImage *blackImg;
	QImage *blankImg;
	QImage *hintImg;

public slots:
	void cellClicked(int x, int y);

};

#endif // REVERSI_H
