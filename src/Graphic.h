

#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#define TOTAL_TILE_LELVEL_1 100

#define TILE_RED 0
#define TILE_BLUE 1
#define TILE_GREEN 2
#define TILE_WIDTH 80
#define TILE_HEIGHT 80

void setClip();

class Graphic
{
public:
	SDL_Texture* loadImage(std::string file,SDL_Renderer *renderer);
	void textureAtPos( SDL_Renderer *renderer, SDL_Texture* texture, int x, int y);
	void tileAtPos(SDL_Renderer *renderer, SDL_Rect *box, int type);
	void renderScene();
	Graphic();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect mWindow;



};
#endif /* _GRAPHIC_H */