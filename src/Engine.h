

#ifndef _ENGINE_H
#define _ENGINE_H


class Engine
{
public:

	Engine();

	void sdlinit(std::string title);
    /*
     *  \brief Used to handle keyboard input.
     *  \param seedAnim Seed for Animation.
     *  \return void
     */
    void handleinput(int seedAnim);

	void update();
    
    static void Quit();

    //Variables
	static Graphic gfx;
	static Timer timer;
    static Character player;
    static Level level;
private:
    SDL_Event event;

};





#endif /* _ENGINE_H */