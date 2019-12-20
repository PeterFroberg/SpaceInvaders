#include "System.h"

System::System() {
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Game", 20, 20, 700, 700, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
	
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	
}

System::~System() {
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);

	Mix_CloseAudio();
	SDL_Quit();
}

System sys;
