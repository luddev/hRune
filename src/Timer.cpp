#include<iostream>
#include"SDL.h"
#include"Timer.h"
#include"Log.h"

Timer::Timer()
{
	startTicks = 0;
	pausedTicks = 0;
	tStarted = false;
	tPaused = false;
}

void Timer::start()
{
	tStarted = true;
	tPaused = false;
	startTicks = SDL_GetTicks();

}

void Timer::stop()
{
	tStarted = false;
	tPaused = false;

}

void Timer::pause()
{
	if(tStarted && !tPaused)
	{
	tPaused = true;
	pausedTicks = SDL_GetTicks() - startTicks;
	Log::Info("Game Paused : %d \n",SDL_GetTicks());
	//std::cout<<"Game Paused : \n"<<SDL_GetTicks()<<std::endl;
	}
}

void Timer::unpause()
{
	if(tPaused)
	{
		tPaused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
		Log::Info("Game UnPaused : %d \n",SDL_GetTicks());
		//std::cout<<"Game UnPaused : \n"<<SDL_GetTicks()<<std::endl;
	}

}

int Timer::restart()
{
	int elapseTicks = ticks();
	start();
	return elapseTicks;
}

int Timer::ticks() const
{
	if(tStarted)
	{
		if(tPaused)
			return pausedTicks;
		else 
			return SDL_GetTicks() - startTicks;
	}
	return 0;

}

bool Timer::started() const
{
	return tStarted;
}

bool Timer::paused() const
{
	return tPaused;
}