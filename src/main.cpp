//SDL Required
#include"SDL.h"
#include<iostream>
#include<string>
//User Includes
#include"Graphic.h"
#include"Engine.h"

int main(int argc, char **argv)
{
	Engine engine;

	try 
	{
		engine.sdlinit("Engine");
		std::cout<<"[*]SDL INIT !\n";
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		engine.Quit();
		return -1;
	}

	engine.renderScene();
	SDL_Delay(2000);


	engine.Quit();
	return 0;
}