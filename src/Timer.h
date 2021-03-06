
#ifndef _TIMER_H
#define _TIMER_H

const int FRAME_PER_SECOND = 30;
class Timer
{
public:
	Timer();
	void start();
	void stop();

	void pause();
	void unpause();

	int restart();

	int ticks() const;
	bool started() const;
	bool paused() const;

private:
    int startTicks, pausedTicks;
    bool tStarted, tPaused;


};

#endif /* _TIMER_H */