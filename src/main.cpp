/*
 *    Copyright (C) 2013  ludkiller
 *
 *    This program is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU General Public License
 *    as published by the Free Software Foundation; either version 2
 *    of the License, or (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


/*
//SDL Required
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#include<string>
//User Includes
//Order of inclusion matters ;) please dont tweak with it
//always keep Graphic above engine
#include"Timer.h"
#include"Tile.h"
#include"Level.h"
#include"Character.h"
#include"Graphic.h"
#include"Engine.h"
#include"Log.h"
*/
#include"Stdincl.h"

int main(int argc, char **argv)
{
	Log::Open("game_log.log");

	Engine engine;

	int seedAnim=0; //seed for our animation ;3
	
	engine.sdlinit("Engine");
	Log::Info("SDL Init !");
    engine.level.loadLevel1();
    //start timer
	engine.timer.start();
	Log::Info("FPS Capped at %d ",FRAME_PER_SECOND);

	while(1)
	{
		++seedAnim;
		if(seedAnim >= 4)
			seedAnim=1;
        //Add loadlevel , update and some more here.

        engine.handleinput(seedAnim);

        engine.update(); // let engine.update call renderscene.

       // engine.gfx.renderScene();

		if(engine.timer.ticks() < (1000/ FRAME_PER_SECOND ))
		{
			SDL_Delay( ( 1000 / FRAME_PER_SECOND ) - engine.timer.ticks() );
			Log::Info("FPS Capped at %d ",FRAME_PER_SECOND);
		}
	
	}
	SDL_Delay(2000);


	Engine::Quit();
	return 0;
}