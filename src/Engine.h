

#ifndef _ENGINE_H
#define _ENGINE_H

#define RED_TILE 1
#define BLUE_TILE 2
#define GREEN_TILE 3

class Engine
{
public:

	void sdlinit(std::string title);
	void Quit();
	void gamelogic();
	void renderScene();
	void setupStageProps();
	void removeStageProps();
	void setupStage1();
	void setupStage2();
	Engine();
	//Variables 
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect mWindow;
	Graphic graphic;

};

#endif /* _ENGINE_H */