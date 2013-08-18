//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<stdlib.h>
#include<string>
//User Includes
#include"Graphic.h"
#include"Engine.h"




Graphic Engine::gfx = Graphic();

Engine::Engine()
{

}



void Engine::sdlinit(std::string title)
{

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		throw std::runtime_error("SDL Init Failed");
	}


	gfx.window = SDL_CreateWindow(title.c_str(),gfx.mWindow.x,gfx.mWindow.y,gfx.mWindow.w,gfx.mWindow.h,0);
	if(gfx.window== nullptr)
	{
		throw std::runtime_error("SDL Create Window Failed\n");
	}

	gfx.renderer = SDL_CreateRenderer(gfx.window,-1,SDL_RENDERER_PRESENTVSYNC);

	if(gfx.renderer == nullptr)
	{
		throw std::runtime_error("SDL Create Renderer Failed\n");
	}
	
	std::cout<<"Renderer Init()"<<std::endl;

}

void Engine::Quit()
{
	
	SDL_DestroyWindow(gfx.window);
	SDL_DestroyRenderer(gfx.renderer);
	SDL_Quit();
	exit(0);
}



void Engine::setupStage1()
{
	gfx.renderScene();
	std::cout<<"Clipping done!\n"<<std::endl;
	
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


