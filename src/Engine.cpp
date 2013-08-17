//SDL Required
#include"SDL.h"
#include<iostream>
#include<string>
//User Includes
#include"Graphic.h"
#include"Engine.h"

Engine::Engine()
{
	window = nullptr;
	renderer = nullptr;
}



void Engine::sdlinit(std::string title)
{

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		throw std::runtime_error("SDL Init Failed");
	}

	mWindow.w = 640;
	mWindow.h = 480;
	mWindow.x = 20;
	mWindow.y = 20;

	window = SDL_CreateWindow(title.c_str(),mWindow.x,mWindow.y,mWindow.w,mWindow.h,SDL_WINDOW_SHOWN);
	if(window== nullptr)
	{
		throw std::runtime_error("SDL Create Window Failed\n");
	}

	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer = nullptr)
	{
		throw std::runtime_error("SDL Create Renderer Failed\n");
	}
	std::cout<<"Renderer Init()"<<std::endl;

}

void Engine::Quit()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Engine::renderScene()
{
	SDL_RenderClear(this->renderer);
	SDL_Texture *tex = nullptr;
	try 
	{
		tex = graphic.loadImage("background.bmp",this->renderer);
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		Quit();
		return;
	}


	graphic.textureAtPos(this->renderer,tex,40,40);

	SDL_RenderPresent(this->renderer);
	SDL_DestroyTexture(tex);
}

void setupStage1()
{


}

void setupStage2()
{


}

void setupStageProps()
{


}

void removeStageProps()
{


}