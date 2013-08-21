

#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#define TOTAL_TILE_LEVEL_1 80

const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_WIDTH = 60;
const int TILE_HEIGHT = 60;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;



class Graphic
{
public:
	Graphic();
	SDL_Texture* loadImage(std::string file);
	void textureAtPos(SDL_Texture* texture, int x, int y,const SDL_Rect *clip);
	void tileAtPos(SDL_Texture *texture,const SDL_Rect *box, int type);
	void renderScene();
	void setBlendMode(SDL_Texture *texture, SDL_BlendMode blending);
	void setAlpha(SDL_Texture *texture, Uint8 alpha);
	void flipTexture(SDL_Texture* texture, const SDL_Rect *player,const SDL_Rect *box, double angle);
	void loadSprites();
	

	SDL_Window* window;
	SDL_Renderer* renderer;
	//SDL_Surface *screenSurface; Old
	SDL_Rect mwindow;
	SDL_Rect camera;

    //Textures for Tile Sheet Required
	SDL_Texture *tilesheet;
    SDL_Texture *player;



};

void setClip(Graphic *gfx);

#endif /* _GRAPHIC_H */