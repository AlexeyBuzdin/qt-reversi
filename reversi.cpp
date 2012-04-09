#include "reversi.h"
typedef unsigned int unint;

#define FIELD_SIZE  8
#define WHITE_PLAYER_TURN -1
#define BLACK_PLAYER_TURN 1

Reversi::Reversi(QWidget *parent) :
		QWidget(parent) {
	ui.setupUi(this);
	gameStatus = WHITE_PLAYER_TURN;
	configureInterface();

}

void Reversi::configureInterface() {
	lGameStatus = findChild<QLabel*>("gameStatus");
	lGameBackground = findChild<QLabel*>("gameField");
	//lGameBackground->hide();

	whiteImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	whiteImg->load("resource/white.png");

	blackImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	blackImg->load("resource/black.png");

	blankImg = new QImage();

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
			fieldStatus[i][j] = 0;
		}
	}
	// Starting chip initialization
	fieldStatus[3][4] = BLACK_PLAYER_TURN;
	fieldStatus[4][3] = BLACK_PLAYER_TURN;
	fieldStatus[3][3] = WHITE_PLAYER_TURN;
	fieldStatus[4][4] = WHITE_PLAYER_TURN;
	refreshField();
}

void Reversi::cellClicked(int x, int y) {
	Lines lines(gameStatus, Point(x, y));
	if (fieldStatus[x][y] == 0 && lines.updateField(fieldStatus, FIELD_SIZE)) {
		refreshField();
	}
}

void Reversi::refreshField() {
	QImage *figure;
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			switch (fieldStatus[i][j]) {
			case -1:
				figure = whiteImg;
				break;
			case 1:
				figure = blackImg;
				break;
			case 0:
				figure = blankImg;
				break;
			}
			gamingField[i][j]->setPixmap(QPixmap::fromImage(*figure));
		}
	}
	// Change player turn
	//gameStatus *= -1;
	switch (gameStatus *= -1) {
	case -1:
		lGameStatus->setText("It\' white player\s turn");
		break;
	case 1:
		lGameStatus->setText("It\' black player\s turn");
		break;
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
