#include "reversi.h"
#include <qmessagebox.h>
typedef unsigned int unint;

#define WHITE_PLAYER_TURN -1
#define BLACK_PLAYER_TURN 1
#define BACKGROUND_SIZE 470

Reversi::Reversi(MainWindow *parent) : QWidget(0) {
	FIELD_SIZE = 8;
	main = parent;
	gameStatus = WHITE_PLAYER_TURN; //Turn zero
	showHints = true;
	playWithAi = false;
	gameOver = false;

	configureInterface();
	newGame();
}

void Reversi::newGame(){
	map = new Map(FIELD_SIZE);

	gameOver = false;
	gameStatus = WHITE_PLAYER_TURN; // Turn zero
	refreshField();
	changePlayer(0); // Change player to turn one
}

void Reversi::configureInterface() {
	ui.setupUi(this);
	this->setFixedSize(BACKGROUND_SIZE, BACKGROUND_SIZE);
	gameScore = new QString("");

	QLabel *background = new QLabel(this);
	QImage *backgroundImg = new QImage(QSize(470, 470), QImage::Format_RGB16);
	backgroundImg->load("resource/field.png");
	background->setPixmap(QPixmap::fromImage(*backgroundImg));

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
	for (unint i = 0; i < FIELD_SIZE; i++) {
		gamingField[i] = new ClickableLabel*[FIELD_SIZE];
		for (unint j = 0; j < FIELD_SIZE; j++) {
			gamingField[i][j] = new ClickableLabel(i, j, this);
			QObject::connect(gamingField[i][j], SIGNAL (clicked(int, int)),
					this, SLOT (cellClicked(int, int)));
		}
	}
}

void Reversi::refreshField() {
	QImage *figure;
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			switch (map->fieldStatus[i][j]) {
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
	// Set score
	map->setScore();
	*gameScore = QString(" Black: %1 | White: %2").arg(map->blackChipCount).arg(map->whiteChipCount);
}

bool Reversi::checkForLegalTurns() {
	bool noLegalTurns = map->noLegalTurns(gameStatus);
	if(noLegalTurns || !showHints){
		return noLegalTurns;
	}
	QList<Point> hintList = map->getActiveTiles(gameStatus);
	for (int t = 0; showHints && t < hintList.size(); t++) {
		int x = hintList.at(t).x;
		int y = hintList.at(t).y;
		if(!map->fieldStatus[x][y]){
			gamingField[x][y]->setPixmap(QPixmap::fromImage(*activeImg));
		}
	}
	return noLegalTurns;
}

void Reversi::changePlayer(int skippedTurns) {
	// Change player turn
	switch (gameStatus *= -1) {
	case WHITE_PLAYER_TURN:
	{
		QString result1 = QString("White player\'s turn");
		result1.append(gameScore);
		main->setStatusBar(&result1);
		break;
	}
	case BLACK_PLAYER_TURN:
	{
		QString result2 = QString("Black player\'s turn");
		result2.append(gameScore);
		main->setStatusBar(&result2);
		break;
	}
	}
	if (checkForLegalTurns() && skippedTurns < 1) {
		changePlayer(1);
	} else if (checkForLegalTurns() && skippedTurns > 0) {
		QString result3 = QString("Game over");
		result3.append(gameScore);
		main->setStatusBar(&result3);
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
		return;
	}
	case 2:{
			QMessageBox msgBox2;
				msgBox2.setText("White player wins");
			if((map->blackChipCount-map->whiteChipCount)< 0){
			}
			else if((map->blackChipCount-map->whiteChipCount)>0){
				msgBox2.setText("Black player wins");
			}
			else {
				msgBox2.setText("Its a draw");
			}

		    msgBox2.setInformativeText(*gameScore);
		    msgBox2.exec();
		    gameOver = true;
		    return;
		}
	}

	if(playWithAi && gameStatus==WHITE_PLAYER_TURN && !gameOver){
		AI *bot = new AI(gameStatus);
		bot->makeTurn(map);
		refreshField();
		changePlayer(0);
	}
}

void Reversi::cellClicked(int x, int y) {
	Lines lines(gameStatus, Point(x, y), map->fieldStatus, FIELD_SIZE);
	if (map->fieldStatus[x][y] == 0) {
		QList<Point> modifiedCells = lines.getActiveTiles();
		if ((modifiedCells.size() > 0)) {
			for (unint i = 0; i < modifiedCells.size(); i++) {
				map->fieldStatus[modifiedCells.at(i).x][modifiedCells.at(i).y] =
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
		checkForLegalTurns();
	}
}

void Reversi::changeAI(){
	playWithAi = !playWithAi;
}

Reversi::~Reversi() {
	for (unint i = 0; i < FIELD_SIZE; i++) {
		delete[] gamingField[i];
	}
	delete[] gamingField;

	delete map;
	delete gameScore;

	delete whiteImg;
	delete blackImg;
	delete blackImg;
}
