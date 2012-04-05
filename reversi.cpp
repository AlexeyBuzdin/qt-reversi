#include "reversi.h"

Reversi::Reversi(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	configureInterface();
}

void Reversi::configureInterface() {
	lGameStatus = findChild<QLabel*>("gameStatus");
	lGameField = findChild<QLabel*>("gameField");

	QImage *gameField = new QImage(QSize(425, 425),  QImage::Format_RGB16);

	gameField->load ("resource/field.png");
	lGameField->setPixmap(QPixmap::fromImage(*gameField));
}

Reversi::~Reversi()
{

}
