
#ifndef _CHARACTER_H
#define _CHARACTER_H

//Character width and height should remain constant 
const int CHARACTER_W = 33;	//Character W in sprite Action : STAND , RUN
const int CHARACTER_H = 33;	//Character H in sprite Action : STAND , RUN

const int CHARACTER_STAND_X = 33;	//Character X coordinate in sprite Action : STAND
const int CHARACTER_STAND_Y = 1;	//Character Y coordinate in sprite Action : STAND


//Multiply the x coordinate by 2 to get other run sprite max by 4

const int CHARACTER_RUN_X = 31;		//Character X coordinate in sprite Action : RUN 
const int CHARACTER_RUN_Y = 79;		//Character Y coordinate in sprite Action : RUN


class Character
{
public:
	Character(Engine *eng, int x, int y);
	void handleInput(int i);
	void showHero();
	void move();
	void setCamera();


private:
	SDL_Rect box,play_t;
	int xVel,yVel;
	float friction;
	SDL_Event event;
	SDL_Texture *player;
	Engine *engine;

};

#endif /* _CHARACTER_H */