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

void Graphic::textureAtPos(SDL_Texture *texture, int x, int y, SDL_Rect *clip = nullptr)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	//SDL_QueryTexture(texture,NULL,NULL,&pos.w,&pos.h);
	pos.w = TILE_WIDTH;
	pos.h = TILE_HEIGHT;
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
	clip[TILE_GREEN].x = 80;
	clip[TILE_GREEN].y = 80;
	clip[TILE_GREEN].w = TILE_WIDTH;
	clip[TILE_GREEN].h = TILE_HEIGHT;
	SDL_Texture *tilesheet;
	tilesheet = nullptr;
	tilesheet = gfx->loadImage("tiles.bmp");
	//gfx->textureAtPos(tilesheet,40,40,&clip[0]);

	gfx->textureAtPos(tilesheet,100,100,&clip[1]);
	SDL_RenderPresent(gfx->renderer);
	
}

void Graphic::renderScene()
{
	SDL_RenderClear(renderer);
	setClip(this);
	//Add Rendering Code Here.
	//textureAtPos(tex,40,40,clip[0]);

	SDL_RenderPresent(renderer);
	
}

