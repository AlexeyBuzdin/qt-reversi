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
	void newGame();

private:
	Ui::ReversiClass ui;

	// Method for UI configuration, used at constructor phase
	void configureInterface();
	// Refreshes the gaming score
	void calculateScore();
	// Returns true if player can not make a legal turn
	bool thereIsNoLegalTurns();
	// Change player turn or ends the game if skippedTurns is 2
	void changePlayer(int skippedTurns);
	// Refreshes UI gaming field with data taken from fieldStatus
	void refreshField();

	bool showHints;
	bool playWithAi;
	unint FIELD_SIZE;

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
	QImage *activeImg;

public slots:
	void cellClicked(int x, int y);

};

#endif // REVERSI_H
