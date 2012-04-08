#include "reversi.h"
#define FIELD_SIZE  8
typedef unsigned int unint;

Reversi::Reversi(QWidget *parent) :
		QWidget(parent) {
	ui.setupUi(this);
	configureInterface();

	cellClicked(3, 3);
	cellClicked(3, 4);
	cellClicked(4, 3);
	cellClicked(4, 4);
 }

void Reversi::configureInterface() {
	lGameStatus = findChild<QLabel*>("gameStatus");
	lGameField = findChild<QLabel*>("gameField");
	lGameField->hide();

	whiteImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	whiteImg->load("resource/white.png");

	blackImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
	blackImg->load("resource/black.png");

	blankImg = new QImage();

	gamingField = new ClickableLabel**[FIELD_SIZE];
	for (unint i = 0; i < FIELD_SIZE; i++) {
		gamingField[i] = new ClickableLabel*[FIELD_SIZE];
		for (unint j = 0; j < FIELD_SIZE; j++) {
			gamingField[i][j] = new ClickableLabel(i, j, this);
			QObject::connect (gamingField[i][j], SIGNAL (clicked(int, int)),
								        this, SLOT (cellClicked(int, int)));
			fieldStatus[i][j] = 0;
		}
	}
}

void Reversi::cellClicked(int x, int y){
	if (fieldStatus[x][y] == 0){
		fieldStatus[x][y] = -1;


		changeField();
	}
}

void Reversi::changeField() {
	QImage *figure;
	for(unint i = 0; i < FIELD_SIZE; i++){
		for(unint j = 0; j < FIELD_SIZE; j++){
			switch (fieldStatus[i][j]) {
				case -1: figure = whiteImg; break;
				case  1: figure = blackImg; break;
				case  0: figure = blankImg; break;
			}
			gamingField[i][j]->setPixmap(QPixmap::fromImage(*figure));
		}
	}
}

Reversi::~Reversi() {
	for (unint i = 0; i < FIELD_SIZE; i++) {
		delete[] gamingField[i];
	}
	delete[] gamingField;

	delete whiteImg;
	delete blackImg;
	delete blackImg;
}
