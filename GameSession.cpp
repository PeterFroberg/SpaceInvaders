#include "GameSession.h"
#include <SDL.h>
#include "System.h"
#include "Sprite.h"
#include <vector>
#include <memory>

#include <iostream> //Only for debbuging ska tas bort

#define FPS 60;

void GameSession::add(std::shared_ptr<Sprite> sprite) {
	added.push_back(sprite);
}

void GameSession::remove(std::shared_ptr<Sprite> sprite) {
	removed.push_back(sprite);
}
//GameSession::GameSession() {

//}

void GameSession::run() {
	bool quit = false;
	Uint32 tickInterval = 1000 / FPS;

	while (!quit) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
 		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT: quit = true; break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case SDLK_LEFT:
					std::cout << "Left arrow pushed\n";
					for (auto s : sprites) {
						s->leftButton();
					}
					break;
				case SDLK_RIGHT:
					std::cout << "Right arrow pushed\n";
					for (auto s : sprites) {
						s->rightButton();
					}
					break;
				case SDLK_SPACE:
					std::cout << "Spacebar pushed\n";
					for (auto s : sprites) {
						s->spaceBar();					
					}
					break;
				}//switch event.key.keysym.sym
			}//switch event.type
		}//Innre While
 		for (auto s : sprites) {
			s -> tick();
		}

		for (auto s : added) {
			sprites.push_back(s);
		}
		added.clear();

		for (auto s : removed) 
			for (auto i = sprites.begin(); i != sprites.end();)
				if (*i == s) {
					i = sprites.erase(i);
				}
				else {
					i++;
				}
		removed.clear();
		

		SDL_SetRenderDrawColor(sys.ren, 0, 0, 0, 0);
		SDL_RenderClear(sys.ren);
		for (auto sprite : sprites) {
			sprite->draw();
		}

		SDL_RenderPresent(sys.ren);

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}//Yttre run loop
}
