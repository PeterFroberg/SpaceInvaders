#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <SDL_mixer.h>

class System
{
public:
	System();
	~System();

	SDL_Window* win;
	SDL_Renderer* ren;
	
};

extern System sys;

#endif
