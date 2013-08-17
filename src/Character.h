
#ifndef _CHARACTER_H
#define _CHARACTER_H


class Character
{
public:
	Character(Engine *eng, int x, int y);
	void handleInput();
	void showHero();
	void move();
	void setCamera();


private:
	SDL_Rect box;
	int xVel,yVel;
	SDL_Event event;
	Engine *engine;

};

#endif /* _CHARACTER_H */