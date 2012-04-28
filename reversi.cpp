#include "reversi.h"
#include <qmessagebox.h>
typedef unsigned int unint;

#define WHITE_PLAYER_TURN -1
#define BLACK_PLAYER_TURN 1

Reversi::Reversi(QWidget *parent) :
		QWidget(parent) {
	FIELD_SIZE = 8;
	ui.setupUi(this);

	this->setFixedSize(60 + FIELD_SIZE * 50, 60 + FIELD_SIZE * 50);
	gameStatus = WHITE_PLAYER_TURN; //Turn zero
	showHints = true;

	configureInterface();

}

void Reversi::newGame(){
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			fieldStatus[i][j] = 0;
		}
	}
	// Starting chip initialization
	fieldStatus[FIELD_SIZE / 2 - 1][FIELD_SIZE / 2] = BLACK_PLAYER_TURN;
	fieldStatus[FIELD_SIZE / 2][FIELD_SIZE / 2 - 1] = BLACK_PLAYER_TURN;
	fieldStatus[FIELD_SIZE / 2 - 1][FIELD_SIZE / 2 - 1] = WHITE_PLAYER_TURN;
	fieldStatus[FIELD_SIZE / 2][FIELD_SIZE / 2] = WHITE_PLAYER_TURN;
	gameStatus = WHITE_PLAYER_TURN; // Turn zero
	refreshField();
	changePlayer(0); // Change player to turn one
}

void Reversi::configureInterface() {

	lGameStatus = findChild<QLabel*>("gameStatus");
	lGameScore = findChild<QLabel*>("gameScore");

	// Load pictures
	whiteImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	whiteImg->load("resource/white.png");

	blackImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	blackImg->load("resource/black.png");

	blankImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	blankImg->load("resource/blank.png");

	activeImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	activeImg->load("resource/active.png");

	// Configure UI game field
	gamingField = new ClickableLabel**[FIELD_SIZE];
	fieldStatus = new int*[FIELD_SIZE];
	for (unint i = 0; i < FIELD_SIZE; i++) {
		gamingField[i] = new ClickableLabel*[FIELD_SIZE];
		fieldStatus[i] = new int[FIELD_SIZE];
		for (unint j = 0; j < FIELD_SIZE; j++) {
			gamingField[i][j] = new ClickableLabel(i, j, this);
			QObject::connect(gamingField[i][j], SIGNAL (clicked(int, int)),
					this, SLOT (cellClicked(int, int)));
		}
	}
	newGame();
}

void Reversi::refreshField() {
	QImage *figure;
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			switch (fieldStatus[i][j]) {
			case WHITE_PLAYER_TURN:
				figure = whiteImg;
				break;
			case BLACK_PLAYER_TURN:
				figure = blackImg;
				break;
			default:
				figure = blankImg;
				break;
			}
			gamingField[i][j]->setPixmap(QPixmap::fromImage(*figure));
		}
	}
	calculateScore();
}

void Reversi::calculateScore() {
	blackChipCount = 0;
	whiteChipCount = 0;
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			if (fieldStatus[i][j] == BLACK_PLAYER_TURN) {
				blackChipCount++;
			}
			if (fieldStatus[i][j] == WHITE_PLAYER_TURN) {
				whiteChipCount++;
			}
		}
	}
	lGameScore->setText(
			QString("Black: %1 | White: %2").arg(blackChipCount).arg(whiteChipCount));
}

bool Reversi::thereIsNoLegalTurns() {
	bool noLegalTurns = true;
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			Lines test(gameStatus, Point(i, j), fieldStatus, FIELD_SIZE);
			QList<Point> activeFields = test.updateField();
			if (fieldStatus[i][j] == 0 && activeFields.size() > 0) {
				noLegalTurns = false;
				for (int t = 0; showHints && (t < activeFields.size()); t++) {
					gamingField[i][j]->setPixmap(
							QPixmap::fromImage(*activeImg));
				}
			}
		}
	}

	return noLegalTurns;
}

void Reversi::changePlayer(int skippedTurns) {
	// Change player turn
	switch (gameStatus *= -1) {
	case WHITE_PLAYER_TURN:
		lGameStatus->setText("White player\'s turn");
		break;
	case BLACK_PLAYER_TURN:
		lGameStatus->setText("Black player\'s turn");
		break;
	}
	if (thereIsNoLegalTurns() && skippedTurns < 1) {
		changePlayer(1);
	} else if (thereIsNoLegalTurns() && skippedTurns > 0) {
		lGameStatus->setText("Game Over");
		skippedTurns++;
	}
	// Counts the amount of time this function was called
	switch (skippedTurns) {
	case 1:{
		QMessageBox msgBox1;
			switch(gameStatus*(-1)){
				case WHITE_PLAYER_TURN:
					msgBox1.setText("White player skips a turn");
					break;
				case BLACK_PLAYER_TURN:
					msgBox1.setText("Black player skips a turn");
					break;
			}
		    msgBox1.exec();
		break;
	}
	case 2:{
			QMessageBox msgBox2;
			if((blackChipCount-whiteChipCount)< 0){
				msgBox2.setText("White player wins");
			}
			else if((blackChipCount-whiteChipCount)>0){
				msgBox2.setText("Black player wins");
			}
			else {
				msgBox2.setText("Its a draw");
			}

		    msgBox2.setInformativeText(lGameScore->text());
		    msgBox2.exec();
		    break;
		}
	}
}

void Reversi::cellClicked(int x, int y) {
	Lines lines(gameStatus, Point(x, y), fieldStatus, FIELD_SIZE);
	if (fieldStatus[x][y] == 0) {
		QList<Point> modifiedCells = lines.updateField();
		if ((modifiedCells.size() > 0)) {
			for (unint i = 0; i < modifiedCells.size(); i++) {
				fieldStatus[modifiedCells.at(i).x][modifiedCells.at(i).y] =
						gameStatus;
			}
			refreshField();
			changePlayer(0);
		}
	}
}
void Reversi::changeShowHint(){
	showHints = !showHints;
	refreshField();
	if(showHints){
		thereIsNoLegalTurns();
	}
}

Reversi::~Reversi() {
	for (unint i = 0; i < FIELD_SIZE; i++) {
		delete[] gamingField[i];
		delete[] fieldStatus[i];
	}
	delete[] gamingField;
	delete[] fieldStatus;

	delete whiteImg;
	delete blackImg;
	delete blackImg;
}
