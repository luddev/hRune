

#ifndef _LEVEL_H
#define _LEVEL_H

#define TOTAL_TILE_LEVEL_1 75
const int TOTAL_TILES = 3;

#include"Character.h"

class Level
{
public:
    Level();

    void setupStage1();
	void setupStage2();

	void loadLevel1();
    bool checkCollisionLevel1(Character *player);


    void destroyTiles();

    Tile *tiles[TOTAL_TILE_LEVEL_1];
private:
    bool loadedtiles;

};


#endif /* _LEVEL_H */