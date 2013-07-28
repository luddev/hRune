/*
 * Engine.cpp
 *
 *  Created on: Jul 27, 2013
 *      Author: ludkiller
 */

#include <SDL2/SDL.h>
#include "Engine.h"


int initSDL(void) {

	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("hRune", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Surface *bmp;
	SDL_Texture *texture;
	ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	bmp = SDL_LoadBMP("24.bmp");
	texture = SDL_CreateTextureFromSurface(ren,bmp);
	SDL_FreeSurface(bmp);
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, texture, NULL, NULL);
	SDL_RenderPresent(ren);
	SDL_Delay(2000);

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	return 1;
}

int loadMap(void) {

	return 0;
}
