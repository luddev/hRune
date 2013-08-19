
#ifndef _CHARACTER_H
#define _CHARACTER_H

//Character width and height should remain constant 
const int CHARACTER_W = 31;	//Character W in sprite Action : STAND , RUN
const int CHARACTER_H = 33;	//Character H in sprite Action : STAND , RUN

const int CHARACTER_STAND_X = 33;	//Character X coordinate in sprite Action : STAND
const int CHARACTER_STAND_Y = 1;	//Character Y coordinate in sprite Action : STAND


//Multiply the x coordinate by 2 to get other run sprite max by 4

const int CHARACTER_RUN_X = 31;		//Character X coordinate in sprite Action : RUN 
const int CHARACTER_RUN_Y = 79;		//Character Y coordinate in sprite Action : RUN

const int CHARACTER_JUMP_X = 255;
const int CHARACTER_JUMP_Y = 0;

class Character
{
public:
	Character(Engine *eng, int x, int y);
	void handleInput(int i);
	void showHero();
	void move();
	void setCamera();
	~Character();


private:
	SDL_Rect box;	//Character Position
	SDL_Rect play_t;	//Character Coordinate in sprite
	int xVel,yVel;
	int xAcl,yAcl;
	double degree;
	float friction;
	SDL_Event event;
	SDL_Texture *player;
	Engine *engine;
	SDL_BlendMode blendin;
	bool isFlip;
};

#endif /* _CHARACTER_H */