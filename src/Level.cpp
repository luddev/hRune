#include<iostream>
#include<fstream>
#include"SDL.h"
#include"SDL_image.h"
#include"Tile.h"
#include"Log.h"
#include"Level.h"
#include"Timer.h"
#include"Character.h"
#include"Graphic.h"
#include"Engine.h"

Level::Level()
{
    loadedtiles = false;
}

void Level::setupStage1()
{
	

}



void Level::setupStage2()
{


}

void Level::loadLevel1()
{
	int i=0;
	std::ifstream map("level1.mxp");




	if(!loadedtiles)
	{
	//Level 1 texture at pos code in here ;)
	int ycord = 0;
	int xcord = 0;
    int tiletype = -1;

	//load tile sheets
	for (i =0 ; i < TOTAL_TILE_LEVEL_1 ; i++)
	{
		map >> tiletype; //always -1 fix this.

		if( ( tiletype >= 0 ) /*&& ( tiletype < TOTAL_TILES ) */ )
        {
            tiles[i] = new Tile(xcord,ycord,tiletype);
        }
       //If we don't recognize the tile type
        else 
        {
            //Stop loading map
            map.close();
            Engine::Quit();
        }
		Log::Info("Placing Tiles , Tile Type ( %d , %d , %d)",xcord,ycord, tiletype);
        // take xcord increment it with size of tile , keeping ycord constant
        //if xcord >= width of screen , increment y 
		xcord += TILE_WIDTH;
		if(xcord >= SCREEN_WIDTH)
		{
			xcord = 0;
			ycord += TILE_HEIGHT;
		}

	}
	Log::Info("Tile Init !\n");
	loadedtiles = true;
	//Place tile sheets
    map.close();
	}

}

void Level::checkCollisionLevel1()
{
    //Add Collision Checking Code here :3

}

void Level::destroyTiles()
{
	int i=0;
	for(i=0;i<TOTAL_TILE_LEVEL_1;i++)
	{
		delete tiles[i];
	}
	Log::Info("Tiles Deleted !\n");
	

}