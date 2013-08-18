//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<string>
//User Includes
#include"Graphic.h"
#include"Engine.h"

SDL_Rect clip[2];

Graphic::Graphic()
{
	window = nullptr;
	renderer = nullptr;
	
	mWindow.w = 800;
	mWindow.h = 600;
	mWindow.x = 20;
	mWindow.y = 20;

}

SDL_Texture* Graphic::loadImage(std::string file)
{
	SDL_Surface *image = nullptr;
	SDL_Texture *texture = nullptr;
	image = SDL_LoadBMP(file.c_str());
	if(image == nullptr)
	{
		throw std::runtime_error("Unable to locate image " + file);
	}

	texture = SDL_CreateTextureFromSurface(renderer,image);
	if(texture == nullptr)
	{
		std::cout<<SDL_GetError()<<std::endl;
		throw std::runtime_error("Failed Creating Texture from surface\n");

	}
	SDL_FreeSurface(image);
	return texture;
}

void Graphic::textureAtPos(SDL_Texture *texture, int x, int y, SDL_Rect *clip)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	//SDL_QueryTexture(texture,NULL,NULL,&pos.w,&pos.h);
	SDL_RenderCopy(renderer,texture,clip,&pos);

}

void Graphic::tileAtPos(SDL_Rect *box, int type)
{
	


}

void setClip(Graphic *gfx)
{

	clip[TILE_RED].x = 0;
	clip[TILE_RED].y = 0;
	clip[TILE_RED].w = TILE_WIDTH;
	clip[TILE_RED].h = TILE_HEIGHT;
	clip[TILE_BLUE].x = 0;
	clip[TILE_BLUE].y = 80;
	clip[TILE_BLUE].w = TILE_WIDTH;
	clip[TILE_BLUE].h = TILE_HEIGHT;
	SDL_Texture *red_t,*blue_t,*tilesheet;
	red_t = blue_t = tilesheet = nullptr;
	tilesheet = gfx->loadImage("tiles.bmp");
	gfx->textureAtPos(tilesheet,40,40,&clip[0]);
	gfx->textureAtPos(tilesheet,50,50,&clip[1]);
	SDL_RenderPresent(gfx->renderer);
}

void Graphic::renderScene()
{
	SDL_RenderClear(renderer);
	SDL_Texture *tex = nullptr;
	try 
	{
		tex = loadImage("background.bmp");
		tex = nullptr;
		tex = loadImage("tiles.bmp");
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		Engine::Quit();
		return;
	}

	//Add Rendering Code Here.
	//textureAtPos(tex,40,40,clip[0]);

	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(tex);
}

