//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<stdlib.h>
#include<string>
//User Includes
#include"Tile.h"
#include"Timer.h"
#include"Graphic.h"
#include"Engine.h"
#include"Log.h"





Graphic Engine::gfx = Graphic();
Timer Engine::timer = Timer();

Engine::Engine()
{
	loadedTiles = false;
}



void Engine::sdlinit(std::string title)
{

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		Log::Error("SDL Init Failed!");
		throw std::runtime_error("SDL Init Failed");
		
	}


	gfx.window = SDL_CreateWindow(title.c_str(),gfx.mWindow.x,gfx.mWindow.y,gfx.mWindow.w,gfx.mWindow.h,0);
	if(gfx.window== nullptr)
	{
		Log::Error("SDL Create Window Failed!");
		throw std::runtime_error("SDL Create Window Failed\n");

	}

	gfx.renderer = SDL_CreateRenderer(gfx.window,-1,SDL_RENDERER_PRESENTVSYNC);

	if(gfx.renderer == nullptr)
	{
		Log::Error("SDL_Create Renderer Failed !");
		throw std::runtime_error("SDL Create Renderer Failed\n");

	}

	// Old Renderer is better ;)
	//gfx.screenSurface = SDL_GetWindowSurface(gfx.window);  
	
	//Log::Info("Renderer Init !");

}

void Engine::Quit()
{

	SDL_DestroyWindow(gfx.window);
	SDL_DestroyRenderer(gfx.renderer);
	IMG_Quit();
	SDL_Quit();
	exit(0);
}



void Engine::setupStage1()
{
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.w = SCREEN_WIDTH;
	topLeftViewport.h = SCREEN_HEIGHT;
	SDL_RenderSetViewport( gfx.renderer, &topLeftViewport );
	SDL_RenderSetScale( gfx.renderer, 1.f, 1.f );
	SDL_SetRenderDrawColor( gfx.renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear(gfx.renderer);
	gfx.loadSprites();
	gfx.renderScene();
	Log::Info("Clipping done");
	
	
	//gfx.renderScene();

}

void Engine::setupStage2()
{


}

void setupStageProps()
{


}

void removeStageProps()
{


}



void Engine::loadLevel1(Tile *tilex[])
{
	int i=0;
	std::ifstream ;

	//Load Tile Sprite


	if(!loadedTiles)
	{
	//Level 1 texture at pos code in here ;)
	int ycord = 0;
	int xcord = 0;
	//load tile sheets
	for (i =0 ; i < TOTAL_TILE_LEVEL_1 ; i++)
	{
		
		
		tilex[i] = new Tile(xcord,ycord,TILE_RED);
		Log::Info("Placing Tiles ( %d , %d )",xcord,ycord);
		//std::cout<<"Placing tiles (x,y) : "<<xcord<<" "<<ycord<<std::endl;
		xcord += TILE_WIDTH;
		if(xcord >= SCREEN_WIDTH)
		{
			xcord = 0;
			ycord += TILE_HEIGHT;
		}

		
	
		
	}
	Log::Info("Tile Init !\n");
	loadedTiles = true;
	//Place tile sheets
	}
	SDL_Rect box;
	for (i=0 ; i < TOTAL_TILE_LEVEL_1 ; i++)
	{
		box = tilex[i]->getBox();
		gfx.tileAtPos(gfx.tilesheet,&box,tilex[i]->getType());
	}
}

void Engine::destroyTiles(Tile *tilex[])
{
	int i=0;
	for(i=0;i<TOTAL_TILE_LEVEL_1;i++)
	{
		delete tilex[i];
	}
	Log::Info("Tiles Deleted !\n");
	

}