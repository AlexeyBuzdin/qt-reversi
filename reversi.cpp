#include "reversi.h"
#define FIELD_SIZE  8
typedef unsigned int unint;

Reversi::Reversi(QWidget *parent) :
		QWidget(parent) {
	ui.setupUi(this);
	configureInterface();

	turn(0, 0, 1);
	turn(0, 1, 1);
	turn(0, 2, 1);
	turn(0, 3, 1);
	turn(0, 4, 1);
	turn(0, 5, 1);
	turn(0, 6, 1);
	turn(0, 7, 1);

	turn(1, 0, 1);
	turn(2, 0, 1);
	turn(3, 0, 1);
	turn(4, 0, 1);
	turn(5, 0, 1);
	turn(6, 0, 1);
	turn(7, 0, 1);

	turn(3, 3, 1);
	turn(3, 4, -1);
	turn(4, 3, -1);
	turn(4, 4, 1);
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
			fieldStatus[i][j] = 0;
		}
	}
}

void Reversi::turn(int x, int y, int turn){
	fieldStatus[x][y] = turn;

	changeField();
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
			//gamingField[i][j]->setPixmap(QPixmap::fromImage(*figure));
			QPixmap* test = new QPixmap(CHIP_SIZE, CHIP_SIZE);
			test->fill(QColor::fromRgb(20,20,20,20));
			gamingField[i][j]->setPixmap(*test);
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
