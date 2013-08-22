/*
#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"

#include"Character.h"
#include"Graphic.h"
#include"Engine.h"
#include"Level.h"
#include"Log.h"
#include"Tile.h"
#include"Timer.h"
*/

#include"Stdincl.h"

Character::Character(int x, int y)
{
	box.x = x;
	box.y = y;
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;

	speedX = 5;
    speedY = 0;
	friction = 0.83;    //Test Different values of friction :3
	acclX = 5;
	acclY = 0;

	play_t.x = CHARACTER_STAND_X;
	play_t.y = CHARACTER_STAND_Y;
	play_t.w = CHARACTER_W;
	play_t.h = CHARACTER_H;
	degree = 0;
	isFlip = false;

	Log::Info("Character Init!");


	
}

void Character::setSpeedX(int speedx)
{
    speedX = speedx;
}
void Character::setSpeedY(int speedy)
{
    speedY = speedy;
}
void Character::setAcclX(int acclx)
{
    acclX = acclx;
}
void Character::setAcclY(int accly)
{
    acclY = accly;
}
void Character::setFlip(bool isflip)
{
    isFlip = isflip;
}
void Character::setBox(SDL_Rect player)
{
    box.x = player.x;
    box.y = player.y;
    box.w = player.w;
    box.h = player.h;
}

int Character::getSpeedX()
{
    return speedX;
}
int Character::getSpeedY()
{
    return speedY;
}
int Character::getAcclX()
{
    return acclX;
}
int Character::getAcclY()
{
    return acclY;
}
bool Character::getFlip()
{
    return isFlip;
}
SDL_Rect Character::getBox()
{
    return box;
}
SDL_Rect Character::getAnimBox()
{
    return play_t;
}


void Character::animatePlayer(int status, int seedAnim, int keypressed)
{
    
    if(status == CHARACTER_STAND)
    {
        //play_t.x = CHARACTER_STAND_X;
        //play_t.y = CHARACTER_STAND_Y;
        speedX *= friction;
        speedY *= friction;
    }
   else if(status == CHARACTER_RUN && keypressed == SDLK_d)
    {
        play_t.x = CHARACTER_RUN_X * seedAnim;
	    play_t.y = CHARACTER_RUN_Y;
	    speedX += acclX;
	    //yVel -= yAcl;
	    isFlip = false;
    }
    else if(status == CHARACTER_RUN && keypressed == SDLK_a)
    {
        play_t.x = CHARACTER_RUN_X * seedAnim;
		play_t.y = CHARACTER_RUN_Y;
		speedX -= acclX;
		//yVel += yAcl;
		isFlip = true;
    }
	else if(status == CHARACTER_JUMP && keypressed == SDLK_SPACE)
    {
        if(isFlip == false)
        {
		    play_t.x = CHARACTER_JUMP_X;
		    play_t.y = CHARACTER_JUMP_Y;
            speedX = 0;
		    speedX += acclX;
		    speedY += 5;
	    }
	    else 
	    {
		    play_t.x = CHARACTER_JUMP_X;
		    play_t.y = CHARACTER_JUMP_Y;
            speedX = 0;
		    speedX -= acclX;
		    speedY -= 5;
	    }
    }
    speedX *= friction;
    speedY *= friction;
    box.x += speedX;
    box.y += speedY;
}
