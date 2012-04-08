#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(int x, int y, QWidget * parent) :
		QLabel(parent) {
	this->xAssis = x;
	this->yAssis = y;
	int j = 50 + ((CHIP_SIZE)*x);
	int i = 30 + ((CHIP_SIZE)*y);
	this->setGeometry(i, j, CHIP_SIZE, CHIP_SIZE);
}

void ClickableLabel::mousePressEvent(QMouseEvent * event) {
	emit clicked(xAssis, yAssis);
}
