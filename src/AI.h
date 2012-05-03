#ifndef AI_H_
#define AI_H_
#include "src/Lines.h"
#include "src/Point.h"
#include "src/Map.h"
#include "src/AI.h"

class AI {
public:
	AI(int gameStatus);
	void makeTurn(Map *map);
	virtual ~AI(){};
private:
	Point getRichestTile(Map *map);
	int player;
};

#endif /* AI_H_ */
