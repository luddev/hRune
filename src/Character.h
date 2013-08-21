
#ifndef _CHARACTER_H
#define _CHARACTER_H

//Character width and height should remain constant 
const int CHARACTER_W = 31;	//Character W in sprite Action : STAND , RUN
const int CHARACTER_H = 33;	//Character H in sprite Action : STAND , RUN

const int CHARACTER_STAND_X = 33;	//Character X coordinate in sprite Action : STAND
const int CHARACTER_STAND_Y = 1;	//Character Y coordinate in sprite Action : STAND


//Multiply the x coordinate by 1,2,3,4 to get other run sprite max by 4

const int CHARACTER_RUN_X = 31;		//Character X coordinate in sprite Action : RUN 
const int CHARACTER_RUN_Y = 79;		//Character Y coordinate in sprite Action : RUN

const int CHARACTER_JUMP_X = 255;
const int CHARACTER_JUMP_Y = 0;

enum characterStatus {
    CHARACTER_STAND = 0,
    CHARACTER_RUN,
    CHARACTER_JUMP,
    CHARACTER_DIE
};

class Character
{
public:
	Character(int x, int y);

    SDL_Rect getBox();
    int getSpeedX();
    int getSpeedY();
    int getAcclX();
    int getAcclY();
    bool getFlip();
    SDL_Rect getAnimBox();

    void setSpeedX(int speedx);
    void setSpeedY(int speey);
    void setAcclX(int acclx);
    void setAcclY(int accly);
    void setFlip(bool isflip);
    void setBox(SDL_Rect player);

    void animatePlayer(int status, int i, int keypressed);

private:
	SDL_Rect box;	//Character Position
	SDL_Rect play_t;	//Character Coordinate in sprite
	int speedX,speedY;
	int acclX,acclY;
	double degree;
	double friction;
	//SDL_Texture *player;
	SDL_BlendMode blendin;
	bool isFlip;
};

#endif /* _CHARACTER_H */