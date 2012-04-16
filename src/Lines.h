#ifndef LINES_H_
#define LINES_H_
#include "src/Point.h"
#include <qlist.h>
using namespace std;
typedef unsigned int unint;

class Lines {
public:
	int chipColor;
	//Starting point
	Point point;
	int **gameField;
	int fieldSize;

	QList<Point> updateField();
	QList<Point> checkALine(Point pattern);

	Lines(int chipColor, Point point, int** field, int fieldSize);
	virtual ~Lines();
};

#endif /* LINES_H_ */
