#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"Tile.h"
#include"Timer.h"
#include"Character.h"
#include"Graphic.h"
#include"Engine.h"
#include"Log.h"
//#include"Stdincl.h"


Tile::Tile( int x, int y, int tipe)
{
	box.x = x;
	box.y = y;
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;
	xVel = 0;
	yVel = 0;
	type = tipe;
}

void Tile::showTile()
{

}

int Tile::getType() const
{
	return type;
}

SDL_Rect Tile::getBox() const
{
	return box;
}


