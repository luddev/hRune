//SDL Required
#include"SDL.h"
#include<iostream>
#include<string>
//User Includes
//Order of inclusion matters ;) please dont tweak with it
//always keep Graphic above engine
#include"Graphic.h"
#include"Engine.h"
#include"Tile.h"
#include"Character.h"



int main(int argc, char **argv)
{
	Engine engine;

	Character player(&engine,320,240);
	try 
	{
		engine.sdlinit("Engine");
		engine.setupStage1();
		std::cout<<"[*]SDL INIT !\n";
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		Engine::Quit();
		return -1;
	}
	
	while(1)
	{
	
	player.handleInput();
	
	}
	SDL_Delay(2000);


	Engine::Quit();
	return 0;
}