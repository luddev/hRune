//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<string>
#include<stdexcept>
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
	int i=0;
	
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
	Character player(&engine,320,240);	//Player spawn coordinates for now
	while(1)
	{
	i++;
	if(i==5)
		i=1;
	player.handleInput(i);

	
	}
	SDL_Delay(2000);


	Engine::Quit();
	return 0;
}
