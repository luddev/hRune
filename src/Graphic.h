

#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#define TOTAL_TILE_LELVEL_1 100

#define TILE_RED 0
#define TILE_GREEN 1
#define TILE_BLUE 2
#define TILE_WIDTH 60
#define TILE_HEIGHT 60



class Graphic
{
public:
	SDL_Texture* loadImage(std::string file);
	void textureAtPos(SDL_Texture* texture, int x, int y,SDL_Rect *clip);
	void tileAtPos(SDL_Rect *box, int type);
	void renderScene();
	void loadLevel1();
	void setBlendMode(SDL_Texture *texture, SDL_BlendMode blending);
	void setAlpha(SDL_Texture *texture, Uint8 alpha);
	void flipTexture(SDL_Texture* texture, SDL_Rect *player,SDL_Rect *box, double angle);
	Graphic();

	SDL_Window* window;
	SDL_Renderer* renderer;
	//SDL_Surface *screenSurface; Old
	SDL_Rect mWindow;



};

void setClip(Graphic *gfx);

#endif /* _GRAPHIC_H */