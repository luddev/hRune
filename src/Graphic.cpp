//SDL Required
#include"SDL.h"
#include<iostream>
#include<string>
//User Includes
#include"Graphic.h"
#include"Engine.h"

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