#include "Map.h"

Map::Map(unint FIELD_SIZE) {
	this->FIELD_SIZE = FIELD_SIZE;
	fieldStatus = new int*[FIELD_SIZE];
	for (unint i = 0; i < FIELD_SIZE; i++) {
		fieldStatus[i] = new int[FIELD_SIZE];
		for (unint j = 0; j < FIELD_SIZE; j++) {
			fieldStatus[i][j] = 0;
		}
	}
// Starting chip initialization
	fieldStatus[FIELD_SIZE / 2 - 1][FIELD_SIZE / 2] = BLACK_PLAYER;
	fieldStatus[FIELD_SIZE / 2][FIELD_SIZE / 2 - 1] = BLACK_PLAYER;
	fieldStatus[FIELD_SIZE / 2 - 1][FIELD_SIZE / 2 - 1] = WHITE_PLAYER;
	fieldStatus[FIELD_SIZE / 2][FIELD_SIZE / 2] = WHITE_PLAYER;
}

void Map::setScore() {
	blackChipCount = 0;
	whiteChipCount = 0;
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			if (fieldStatus[i][j] == BLACK_PLAYER) {
				blackChipCount++;
			}
			if (fieldStatus[i][j] == WHITE_PLAYER) {
				whiteChipCount++;
			}
		}
	}
}

bool Map::noLegalTurns(int gameStatus) {
	return getActiveTiles(gameStatus).size() == 0;
}

QList<Point> Map::getActiveTiles(int gameStatus){
	QList<Point> allActiveFields;
	for (unint i = 0; i < FIELD_SIZE; i++) {
		for (unint j = 0; j < FIELD_SIZE; j++) {
			if(fieldStatus[i][j] == 0){
				Lines test(gameStatus, Point(i, j), fieldStatus, FIELD_SIZE);
				allActiveFields.append(test.getActiveTiles());
			}
		}
	}
	return allActiveFields;
}

Map::~Map() {
	for (unint i = 0; i < FIELD_SIZE; i++) {
		delete[] fieldStatus[i];
	}
	delete[] fieldStatus;
}

