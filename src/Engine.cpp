//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<stdlib.h>
#include<string>
//User Includes
#include"Tile.h"
#include"Timer.h"
#include"Graphic.h"
#include"Log.h"
#include"Character.h"
#include"Engine.h"





Graphic Engine::gfx = Graphic();
Timer Engine::timer = Timer();
Character Engine::player = Character(320,240);

Engine::Engine()
{
	loadedtiles = false;
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

}



void Engine::setupStage1()
{
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
    SDL_RenderClear(gfx.renderer);
	gfx.loadSprites();  //Load Sprite Sheets
	gfx.renderScene();  //Render Scene
	Log::Info("Clipping done");
	
	
	//gfx.renderScene();

}

void Engine::setupStage2()
{


}

void Engine::loadLevel1()
{
	int i=0;
	//std::ifstream ;

	//Load Tile Sprite


	if(!loadedtiles)
	{
	//Level 1 texture at pos code in here ;)
	int ycord = 0;
	int xcord = 0;
	//load tile sheets
	for (i =0 ; i < TOTAL_TILE_LEVEL_1 ; i++)
	{
		
		
		tiles[i] = new Tile(xcord,ycord,TILE_RED);
		Log::Info("Placing Tiles ( %d , %d )",xcord,ycord);
        // take xcord increment it with size of tile , keeping ycord constant
        //if xcord >= width of screen , increment y 
		xcord += TILE_WIDTH;
		if(xcord >= SCREEN_WIDTH)
		{
			xcord = 0;
			ycord += TILE_HEIGHT;
		}

		
	
		
	}
	Log::Info("Tile Init !\n");
	loadedtiles = true;
	//Place tile sheets
	}

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
		    destroyTiles();
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
		box = tiles[i]->getBox();
		gfx.tileAtPos(gfx.tilesheet,&box,tiles[i]->getType());
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


void Engine::destroyTiles()
{
	int i=0;
	for(i=0;i<TOTAL_TILE_LEVEL_1;i++)
	{
		delete tiles[i];
	}
	Log::Info("Tiles Deleted !\n");
	

}

void Engine::Quit()
{
    //Destroy Window
    //Destroy Renderer
	SDL_DestroyWindow(gfx.window);
	SDL_DestroyRenderer(gfx.renderer);
	IMG_Quit();
	SDL_Quit();
	Log::Close();
	exit(0);
}