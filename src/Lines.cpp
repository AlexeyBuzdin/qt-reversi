#include "Lines.h"
typedef unsigned int unint;

Lines::Lines( int chipColor, Point point) {
	this->chipColor = chipColor;
	this->point = point;
}

int Lines::updateField(int ** gameField, int length) {
	int result = 0;

	// Vertical line check
	Point start(-1, -1);
	Point end(-1, -1);
	for (int i = 0; i < length; i++){
		if (gameField[point.x][i] == chipColor){
			start.x = point.x;
			start.y = i;
			break;
		}
	}

	for (int i = length -1; i >= 0; i--){
		if (gameField[point.x][i] == chipColor){
			end.x = point.x;
			end.y = i;
			break;
		}
	}

	if(start != end){
		gameField[point.x][point.y] = chipColor;
		return 1;
	}
	return 0;
}

