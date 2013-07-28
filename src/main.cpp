/*
 * main.cpp
 *
 *  Created on: Jul 27, 2013
 *      Author: ludkiller
 *      license: GNU GPL v2
 */


#include <SDL2/SDL.h>
#include "Log.h"
#include "Engine/Engine.h"
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)	{

	if(initSDL())	{
		printf("[*]Init SDL!");

	}

	getchar();
	SDL_Quit();
	return 0;
}

