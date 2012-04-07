#include "reversi.h"
#define FIELD_SIZE  8
typedef unsigned int unint;

Reversi::Reversi(QWidget *parent) :
		QWidget(parent) {
	ui.setupUi(this);
	configureInterface();
	changeField(3, 3, black);
	changeField(3, 4, white);
	changeField(4, 3, white);
	changeField(4, 4, black);
}

void Reversi::configureInterface() {
	lGameStatus = findChild<QLabel*>("gameStatus");
	lGameField = findChild<QLabel*>("gameField");
	lGameField->hide();

	whiteImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	whiteImg->load("resource/white.png");

	blackImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	blackImg->load("resource/black.png");

	gamingField = new QLabel**[FIELD_SIZE];
	for (unint i = 0; i < FIELD_SIZE; i++) {
		gamingField[i] = new QLabel*[FIELD_SIZE];
		for (unint j = 0; j < FIELD_SIZE; j++) {
			QString cellAdress = "cell" + QString::number(i)
					+ QString::number(j);
			gamingField[i][j] = findChild<QLabel*>(cellAdress);
		}
	}
}

void Reversi::changeField(int x, int y, Turn turn) {
	QImage *figure;
	switch (turn) {
		case white: figure = whiteImg; break;
		case black: figure = blackImg; break;
	}
	gamingField[x][y]->setPixmap(QPixmap::fromImage(*figure));
}

Reversi::~Reversi() {
	for (unint i = 0; i < FIELD_SIZE; i++) {
		delete[] gamingField[i];
	}
	delete[] gamingField;
	delete whiteImg;
	delete blackImg;
}
