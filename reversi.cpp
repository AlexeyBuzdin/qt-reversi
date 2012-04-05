#include "reversi.h"
#define FIELD_SIZE  8
typedef unsigned int unint;

Reversi::Reversi(QWidget *parent) :
		QWidget(parent) {
	ui.setupUi(this);
	configureInterface();
}

void Reversi::configureInterface() {
	lGameStatus = findChild<QLabel*>("gameStatus");
	lGameField = findChild<QLabel*>("gameField");
	lGameField->hide();

	white = new QImage(QSize(50, 50), QImage::Format_RGB16);
	white->load("resource/white.png");

	black = new QImage(QSize(50, 50), QImage::Format_RGB16);
	black->load("resource/black.png");

	gamingField = new QLabel**[FIELD_SIZE];
	for (unint i = 0; i < FIELD_SIZE ; i++) {
		gamingField[i] = new QLabel*[FIELD_SIZE];
		for (unint j = 0; j < FIELD_SIZE; j++) {
			QString cellAdress = "cell" + QString::number(i) + QString::number(j);
			gamingField[i][j] = findChild<QLabel*>(cellAdress);
			gamingField[i][j]->setPixmap(QPixmap::fromImage(*white));
		}
	}
}

Reversi::~Reversi() {
	for (unint i = 0; i < FIELD_SIZE; i++) {
		delete[] gamingField[i];
	}
	delete[] gamingField;
	delete white;
	delete black;
}
