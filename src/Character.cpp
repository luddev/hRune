#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"Graphic.h"
#include"Engine.h"
#include"Tile.h"
#include"Character.h"


Character::Character(Engine *eng, int x, int y)
{
	engine = eng; 
	box.x = x;
	box.y = y;
	player = eng->gfx.loadImage("player_t.png");
	play_t.x = 33;
	play_t.y = 1;
	play_t.w = CHARACTER_WIDTH;
	play_t.h = CHARACTER_HEIGHT;
	eng->gfx.textureAtPos(player, box.x, box.y , &play_t);
	std::cout<<"Character Init !"<<std::endl;
	eng->gfx.renderScene();
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