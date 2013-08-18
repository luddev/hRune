#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"Graphic.h"
#include"Engine.h"
#include"Character.h"
#include"Tile.h"

Tile::Tile( int x, int y, int tipe)
{
	box.x = x;
	box.y = y;
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;

	type = tipe;
}

void Tile::showTile()
{

}

int Tile::getType()
{
	return type;
}

SDL_Rect Tile::getBox()
{
	return box;
}