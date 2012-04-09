#include "Point.h"

bool Point::operator!=(Point point){
	return (point.x != this->x) && (point.y != this->y);
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

