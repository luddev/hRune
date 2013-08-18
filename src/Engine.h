

#ifndef _ENGINE_H
#define _ENGINE_H


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



	Engine();
	//Variables
	static Graphic gfx;

};



#endif /* _ENGINE_H */