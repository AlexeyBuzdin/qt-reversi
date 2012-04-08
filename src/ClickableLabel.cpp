#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(int x, int y, QWidget * parent) :
		QLabel(parent) {
	this->xAssis = x;
	this->yAssis = y;
	int j = 50 + ((CHIP_SIZE)*x);
	int i = 40 + ((CHIP_SIZE)*y);
	this->setGeometry(i, j, 50, 50);
}

void ClickableLabel::mousePressEvent(QMouseEvent * event) {
	emit clicked(xAssis, yAssis);
}
