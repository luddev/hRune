

#ifndef _ENGINE_H
#define _ENGINE_H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


class Engine
{
public:

	void sdlinit(std::string title);
	static void Quit();
	void gamelogic();
	void setupStageProps();
	void removeStageProps();
	void setupStage1();
	void setupStage2();
	void loadLevel1(Tile *tilex[]);
	void destroyTiles(Tile *tilex[]);

	Engine();
	//Variables
	static Graphic gfx;
	static Timer timer;
private:
	bool loadedTiles;

};




#endif /* _ENGINE_H */