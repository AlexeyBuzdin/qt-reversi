#ifndef MAP_H_
#define MAP_H_
typedef unsigned int unint;

#define WHITE_PLAYER -1
#define BLACK_PLAYER 1

#include "src/Lines.h"
#include "src/Point.h"

class Map {
public:
	Map(unint FIELD_SIZE);
	virtual ~Map();

	unint FIELD_SIZE;

	int blackChipCount;
	int whiteChipCount;

	void setScore();
	QList<Point> getActiveTiles(int gameStatus);
	bool noLegalTurns(int gameStatus);

	// Game field
	int **fieldStatus;
};

#endif /* MAP_H_ */
