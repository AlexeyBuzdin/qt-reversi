#ifndef LINES_H_
#define LINES_H_
#include "src/Point.h"
typedef unsigned int unint;

class Lines {
public:
	int chipColor;
	//Starting point
	Point point;

	int updateField(int**, int);

	Lines(int chipColor, Point point);
	virtual ~Lines(){};
};

#endif /* LINES_H_ */
