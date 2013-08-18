
#ifndef _CHARACTER_H
#define _CHARACTER_H

const int CHARACTER_HEIGHT = 32;
const int CHARACTER_WIDTH = 29;

class Character
{
public:
	Character(Engine *eng, int x, int y);
	void handleInput();
	void showHero();
	void move();
	void setCamera();


private:
	SDL_Rect box,play_t;
	int xVel,yVel;
	SDL_Event event;
	SDL_Texture *player;
	Engine *engine;

};

#endif /* _CHARACTER_H */