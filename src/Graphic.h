

#ifndef _GRAPHIC_H
#define _GRAPHIC_H

class Graphic
{
public:
	SDL_Texture* loadImage(std::string file,SDL_Renderer *renderer);
	void textureAtPos( SDL_Renderer *renderer, SDL_Texture* texture, int x, int y);

private:



};
#endif /* _GRAPHIC_H */