

#ifndef _ENGINE_H
#define _ENGINE_H


class Engine
{
public:

	Engine();

	void sdlinit(std::string title);
	static void Quit();

	void setupStage1();
	void setupStage2();
	void loadLevel1();
	void destroyTiles();
    void update();
    void handleinput(int seedAnim);
	
	//Variables
	static Graphic gfx;
	static Timer timer;
    static Character player;
    Tile *tiles[TOTAL_TILE_LEVEL_1];
private:
	bool loadedtiles;
    SDL_Event event;

};





#endif /* _ENGINE_H */