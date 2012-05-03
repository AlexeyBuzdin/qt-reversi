#ifndef CLICKABLELABEL_H_
#define CLICKABLELABEL_H_

#include <QtGui/QLabel>
#define CHIP_SIZE 50

class ClickableLabel: public QLabel {
	Q_OBJECT
public:
	ClickableLabel(int x, int y, QWidget * parent = 0);
	virtual ~ClickableLabel();

signals:
	void clicked(int x, int y);

protected:
	int xAssis;
	int yAssis;
	void mousePressEvent ( QMouseEvent * event ) ;
};

#endif /* CLICKABLELABEL_H_ */
