//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<stdlib.h>
#include<string>
//User Includes
#include"Tile.h"
#include"Timer.h"
#include"Level.h"
#include"Graphic.h"
#include"Log.h"
#include"Character.h"
#include"Engine.h"



Graphic Engine::gfx = Graphic();
Timer Engine::timer = Timer();
Character Engine::player = Character(320,240);
Level Engine::level = Level();

Engine::Engine()
{

}



void Engine::sdlinit(std::string title)
{

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		Log::Error("SDL Init Failed!");
		
	}


	gfx.window = SDL_CreateWindow(title.c_str(),gfx.mwindow.x,gfx.mwindow.y,gfx.mwindow.w,gfx.mwindow.h,0);
	if(gfx.window== nullptr)
	{
		Log::Error("SDL Create Window Failed!");

	}

	gfx.renderer = SDL_CreateRenderer(gfx.window,-1,SDL_RENDERER_PRESENTVSYNC);

	if(gfx.renderer == nullptr)
	{
		Log::Error("SDL_Create Renderer Failed !");

	}

	// Old Renderer is better ;)
	//gfx.screenSurface = SDL_GetWindowSurface(gfx.window);  
	
	Log::Info("Renderer Init !");

    //Might as well split this into  2 function or w/e

    gfx.loadSprites();  //Load Sprite Sheets
    Log::Info("Sprite Sheet Loaded");
    SDL_RenderClear(gfx.renderer);  //Clean Renderer


        //View Port Code , is this thing more like camera.
    // find more about this.
    /*
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.w = SCREEN_WIDTH;
	topLeftViewport.h = SCREEN_HEIGHT;
	SDL_RenderSetViewport( gfx.renderer, &topLeftViewport );
	SDL_RenderSetScale( gfx.renderer, 1.f, 1.f );
	SDL_SetRenderDrawColor( gfx.renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	*/

}




void Engine::handleinput(int seedAnim)
{
    //SDL_Rect playercord;
    if(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_w:

					break;
				case SDLK_s:

					break;
				case SDLK_d:
                    player.animatePlayer(CHARACTER_RUN,seedAnim,SDLK_d);

					break;
				case SDLK_a:
                    player.animatePlayer(CHARACTER_RUN,seedAnim,SDLK_a);
					break;
				case SDLK_SPACE:
                    player.animatePlayer(CHARACTER_JUMP,seedAnim,SDLK_SPACE);
                    break;
				case SDLK_p:
					if(timer.paused())
					{
						timer.pause();
					}
					else
					{
						timer.unpause();
					}
					break;
			}

		}
		else if(event.type == SDL_QUIT)
        {
            level.destroyTiles();
            Quit();
		}
        else
        {
            player.animatePlayer(CHARACTER_STAND, seedAnim , 0);
        }

		
	}

}

void Engine::update()
{
    SDL_Rect box;
    SDL_Rect animbox;
    int i = 0;
	for (i=0 ; i < TOTAL_TILE_LEVEL_1 ; i++)
	{
		box = level.tiles[i]->getBox();
		gfx.tileAtPos(gfx.tilesheet,&box,level.tiles[i]->getType());
	}
    box = player.getBox();
    animbox = player.getAnimBox();
    if(!player.getFlip())
    {
        
        gfx.textureAtPos(gfx.player,box.x,box.y,&animbox);
    }
    else
    {
        gfx.flipTexture(gfx.player,&animbox,&box,0);
    }
    gfx.renderScene();
}


void Engine::Quit()
{
    //Destroy Window
    //Destroy Renderer
	SDL_DestroyWindow(gfx.window);
	SDL_DestroyRenderer(gfx.renderer);
	IMG_Quit();
	SDL_Quit();
    Log::Info("QUIT ");
	Log::Close();
	exit(0);
}