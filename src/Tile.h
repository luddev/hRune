
#ifndef _TILE_H
#define _TILE_H




class Tile
{
public:

	Tile(int x, int y, int type);
	void showTile();
	int getType();
	SDL_Rect getBox();

private:

	SDL_Rect box;
	int xVel,yVel;
	int type;

};

#endif /* _TILE_H*/