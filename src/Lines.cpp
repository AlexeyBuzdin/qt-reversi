#include "Lines.h"
typedef unsigned int unint;

Lines::Lines(int chipColor, Point point, int** field, int fieldSize) {
	this->chipColor = chipColor;
	this->point = point;
	gameField = field;
	this->fieldSize = fieldSize;
}

QList<Point> Lines::updateField() {
	gameField[point.x][point.y] = chipColor;

	QList<Point> result;

	// Vertical and horizontal checks
	result.append(checkALine(Point(0, 1)));
	result.append(checkALine(Point(1, 0)));
	result.append(checkALine(Point(0, -1)));
	result.append(checkALine(Point(-1, 0)));

	// Diagonal checks
	result.append(checkALine(Point(1, 1)));
	result.append(checkALine(Point(-1, -1)));
	result.append(checkALine(Point(-1, 1)));
	result.append(checkALine(Point(1, -1)));

	if (result.size() > 0) {
		for (unint i = 0; i < result.size(); i++) {
			gameField[result.at(i).x][result.at(i).y] = chipColor;
		}
		return result;
	} else {
		gameField[point.x][point.y] = 0;
		return result;
	}

}

QList<Point> Lines::checkALine(Point pattern) {
	Point end(-1, -1);
	bool isActive = false;
	QList<Point> result;
	for (int x = point.x + pattern.x, y = point.y + pattern.y;
			(x >= 0 && x < fieldSize) && (y >= 0 && y < fieldSize);
			x += pattern.x, y += pattern.y) {
		if ((gameField[x][y] == chipColor)) {
			end.x = x;
			end.y = y;
			isActive = true;
			break;
		} else if (gameField[x][y] == 0) {
			break;
		} else {
			result.push_back(Point(x, y));
		}
	}
	if (isActive) {
		return result;
	} else {
		return QList<Point>();
	}
}
