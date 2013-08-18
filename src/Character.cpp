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

	xVel = 5;
	yVel = 0;
	friction = 0.9;

	player = eng->gfx.loadImage("../res/player_t.png");
	play_t.x = CHARACTER_STAND_X;
	play_t.y = CHARACTER_STAND_Y;
	play_t.w = CHARACTER_W;
	play_t.h = CHARACTER_H;
	eng->gfx.textureAtPos(player, box.x, box.y , &play_t);
	std::cout<<"Character Init !"<<std::endl;
	eng->gfx.renderScene();
}

void Character::handleInput(int i)
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
					play_t.x = CHARACTER_RUN_X * i;
					play_t.y = CHARACTER_RUN_Y;
					box.x += xVel * i;
					box.y += yVel;
					break;
				case SDLK_a:

					break;
			}

		}
		else if(event.type == SDL_QUIT)
		{
			engine->Quit();
		}
		else
		{
			play_t.x = CHARACTER_STAND_X;
			play_t.y = CHARACTER_STAND_Y;
			//xVel = xVel * friction; // Too much friction can't move fix this.
			yVel = yVel * friction;

		}
		engine->gfx.textureAtPos(player, box.x, box.y , &play_t);
		engine->gfx.renderScene();
	}

}