//SDL Required
#include"SDL.h"
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
	
	mWindow.w = 640;
	mWindow.h = 480;
	mWindow.x = 20;
	mWindow.y = 20;

}

SDL_Texture* Graphic::loadImage(std::string file, SDL_Renderer *renderer)
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

void Graphic::textureAtPos(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(texture,NULL,NULL,&pos.w,&pos.h);
	SDL_RenderCopy(renderer,texture,NULL,&pos);

}

void Graphic::tileAtPos(SDL_Renderer *renderer, SDL_Rect *box, int type)
{
	


}

void setClip()
{
	clip[TILE_RED].x = 0;
	clip[TILE_RED].y = 0;
	clip[TILE_RED].w = TILE_WIDTH;
	clip[TILE_RED].h = TILE_HEIGHT;
	clip[TILE_BLUE].x = 0;
	clip[TILE_BLUE].y = 80;
	clip[TILE_BLUE].w = TILE_WIDTH;
	clip[TILE_BLUE].h = TILE_HEIGHT;
}

void Graphic::renderScene()
{
	SDL_RenderClear(renderer);
	SDL_Texture *tex = nullptr;
	try 
	{
		tex = loadImage("background.bmp",renderer);
		tex = nullptr;
		tex = loadImage("tiles.png",renderer);
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		Engine::Quit();
		return;
	}

	//Add Rendering Code Here.
	textureAtPos(renderer,tex,40,40);

	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(tex);
}

