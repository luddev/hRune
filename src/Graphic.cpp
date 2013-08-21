//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<string>
//User Includes
#include"Tile.h"
#include"Timer.h"
#include"Character.h"
#include"Graphic.h"
#include"Engine.h"
#include"Log.h"
//#include"stdincl.h"

SDL_Rect clip[3];


Graphic::Graphic()
{
	window = nullptr;
	renderer = nullptr;
	
	mwindow.w = SCREEN_WIDTH;
	mwindow.h = SCREEN_HEIGHT;
	mwindow.x = 20;
	mwindow.y = 20;
	camera.x = 0;
	camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;

}

SDL_Texture* Graphic::loadImage(std::string file)
{
	SDL_Surface *image = nullptr;
	SDL_Texture *texture = nullptr;
	image = IMG_Load(file.c_str());
	if(image == nullptr)
	{
		Log::Warning("Unable to locate image %s",file);
		Engine::Quit();
	}

	texture = SDL_CreateTextureFromSurface(renderer,image);
	if(texture == nullptr)
	{
		Log::Warning("Failed Creating Texture From Surface \nError : %s",SDL_GetError());
		//std::cout<<SDL_GetError()<<std::endl;
		Engine::Quit();

	}
	SDL_FreeSurface(image);
	return texture;
}

void Graphic::textureAtPos(SDL_Texture *texture, int x, int y, const SDL_Rect *clip)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	//SDL_QueryTexture(texture,NULL,NULL,&pos.w,&pos.h);
	pos.w = TILE_WIDTH;
	pos.h = TILE_HEIGHT;
	SDL_RenderCopy(renderer,texture,clip,&pos);
	

}

void Graphic::tileAtPos(SDL_Texture *texture,const SDL_Rect *box, int type)
{

	SDL_RenderCopy(renderer, texture, &clip[type], box);

}

void setClip(Graphic *gfx)
{
	//RED TILE
	clip[TILE_RED].x = 0;
	clip[TILE_RED].y = 0;
	clip[TILE_RED].w = TILE_WIDTH;
	clip[TILE_RED].h = TILE_HEIGHT;
	//GREEN TILE
	clip[TILE_GREEN].x = 0;
	clip[TILE_GREEN].y = 80;
	clip[TILE_GREEN].w = TILE_WIDTH;
	clip[TILE_GREEN].h = TILE_HEIGHT;
	//BLUE TILE
	clip[TILE_BLUE].x = 0;
	clip[TILE_BLUE].y = 160;
	clip[TILE_BLUE].w = TILE_WIDTH;
	clip[TILE_BLUE].h = TILE_HEIGHT;
	
	//Load Tile Sheet

	
}

void Graphic::renderScene()
{


	setClip(this);
	//Add Rendering Code Here.
	//textureAtPos(tex,40,40,clip[0]);
	//Render :) Pew pew pew!
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
	
}




void Graphic::setBlendMode( SDL_Texture *texture, SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( texture, blending );
}
		
void Graphic::setAlpha(SDL_Texture *texture, Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( texture, alpha );
	Log::Info("Alpha Blending\n");
}

void Graphic::flipTexture(SDL_Texture* texture, const SDL_Rect *srcclip , const SDL_Rect *destbox, double angle)
{
	SDL_RenderCopyEx(renderer,texture,srcclip,destbox,angle,NULL,SDL_FLIP_HORIZONTAL);

}

void Graphic::loadSprites()
{
	tilesheet = loadImage("../res/tiles.png");
    player = loadImage("../res/player_t.png");

}