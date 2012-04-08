#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(int x, int y, QWidget * parent) :
		QLabel(parent) {
	this->xAssis = x;
	this->yAssis = y;
	int j = 50 + ((CHIP_SIZE)*x);
	int i = 40 + ((CHIP_SIZE)*y);
	this->setGeometry(i, j, 50, 50);
	connect(this, SIGNAL( clicked(int, int) ), this, SLOT( slotClicked(int, int) ));
}

void ClickableLabel::slotClicked(int x, int y) {
	QImage *whiteImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
		whiteImg->load("resource/white.png");
	//	this->setStyleSheet("border: 2px solid");
	this->setPixmap(QPixmap::fromImage(*whiteImg));
}

void ClickableLabel::mousePressEvent(QMouseEvent * event) {
	emit clicked(xAssis, yAssis);
}
