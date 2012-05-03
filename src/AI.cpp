#include "AI.h"

AI::AI(int gameStatus) {
	player = gameStatus;
}

void AI::makeTurn(Map *map){
	Point richestTile = getRichestTile(map);
	Lines lines(player, richestTile, map->fieldStatus, map->FIELD_SIZE);

	QList<Point> modifiedCells = lines.getActiveTiles();
	for (unint i = 0; i < modifiedCells.size(); i++) {
		map->fieldStatus[modifiedCells.at(i).x][modifiedCells.at(i).y] =
				player;
	}
}

Point AI::getRichestTile(Map *map){
	QList<Point> hintList = map->getActiveTiles(player);
	int richestTileCount = 0;
	Point richestTile = Point(0, 0);
	for (unint i = 0; i < map->FIELD_SIZE; i++) {
		for (unint j = 0; j < map->FIELD_SIZE; j++) {
			if(map->fieldStatus[i][j] == 0){
				Lines test(player, Point(i, j), map->fieldStatus, map->FIELD_SIZE);
				if(test.getActiveTiles().size() > richestTileCount){
					richestTileCount = test.getActiveTiles().size();
					richestTile = Point(i, j);
				}
			}
		}
	}
	return richestTile;
}
