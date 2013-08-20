#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"Tile.h"
#include"Timer.h"
#include"Graphic.h"
#include"Engine.h"
#include"Character.h"
#include"Log.h"


Character::Character(Engine *eng, int x, int y)
{
	engine = eng; 
	box.x = x;
	box.y = y;
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;

	xVel = 5;
	yVel = 0;
	friction = 0.6;
	xAcl = 5;
	yAcl = 0;

	player = eng->gfx.loadImage("../res/player_t.png");
	play_t.x = CHARACTER_STAND_X;
	play_t.y = CHARACTER_STAND_Y;
	play_t.w = CHARACTER_W;
	play_t.h = CHARACTER_H;
	degree = 0;
	isFlip = false;

	eng->gfx.textureAtPos(player, box.x, box.y , &play_t);
	Log::Info("Character Init! \n");
	//eng->gfx.setAlpha(player, 0);
	//eng->gfx.setBlendMode(player,belndin); Setup blending later
	eng->gfx.renderScene();

	
}

Character::~Character()
{
	SDL_DestroyTexture(player);
}

void Character::handleInput(int i, Tile *tilex[])
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
					xVel += xAcl;
					//yVel -= yAcl;
					isFlip = false;
					break;
				case SDLK_a:
					play_t.x = CHARACTER_RUN_X * i;
					play_t.y = CHARACTER_RUN_Y;
					xVel -= xAcl;
					//yVel += yAcl;
					isFlip = true;
					break;
				case SDLK_SPACE:
					if(isFlip == false)
					{
						play_t.x = CHARACTER_JUMP_X;
						play_t.y = CHARACTER_JUMP_Y;
						xVel += xAcl;
						yVel += 5;
						break;
					}
					else 
					{
						play_t.x = CHARACTER_JUMP_X;
						play_t.y = CHARACTER_JUMP_Y;
						xVel -= xAcl;
						yVel -= 5;
						break;
					}
				case SDLK_p:
					if(!engine->timer.paused())
					{
						engine->timer.pause();
					}
					else
					{
						engine->timer.unpause();
					}
						break;
			}

		}
		else if(event.type == SDL_QUIT)
		{
			engine->destroyTiles(tilex);
			engine->Quit();
		}
		else
		{
			//play_t.x = CHARACTER_STAND_X;
			//play_t.y = CHARACTER_STAND_Y;
			 // Too much friction can't move fix this.
			xVel = xVel * friction;
			yVel = yVel * friction;
		}
		
		
		box.x += xVel;
		box.y += yVel;
		showHero(); //Render Hero On Screen

		
	}

}

void Character::showHero()
{
	if(isFlip == false)
	{
		engine->gfx.textureAtPos(player, box.x, box.y , &play_t);
	}
	else
	{
			//flipping code here
			engine->gfx.flipTexture(player,&play_t,&box,degree);
	}
	engine->gfx.renderScene();
}