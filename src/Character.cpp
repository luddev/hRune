#include<iostream>
#include<string>
#include"SDL.h"
#include"Graphic.h"
#include"Engine.h"
#include"Tile.h"
#include"Character.h"


Character::Character(Engine *eng, int x, int y)
{
	engine = eng; 
	box.x = x;
	box.y = y;
}

void Character::handleInput()
{
	if(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_w:
					break;
				case SDLK_s:
					break;
				case SDLK_d:
					break;
				case SDLK_a:
					break;
			}

		}
		else if(event.type == SDL_QUIT)
		{
			engine->Quit();
		}
	}

}