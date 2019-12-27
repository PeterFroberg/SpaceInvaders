#include "GameSession.h"
#include <SDL.h>
#include "System.h"
#include "Sprite.h"
#include <vector>
#include <memory>
#include <typeinfo>

#include <iostream> //Only for debbuging ska tas bort

#define FPS 60;

void GameSession::add(std::shared_ptr<Sprite> sprite) {
	added.push_back(sprite);
}

void GameSession::remove(std::shared_ptr<Sprite> sprite) {
	removed.push_back(sprite);
}

void GameSession::addMissile(std::shared_ptr<Sprite> sprite, const int maxNoMissiles) {
	if (missiles.size() < maxNoMissiles) {
		addedMissile.push_back(sprite);
	}
}

void GameSession::removeMissile(std::shared_ptr<Sprite> sprite) {
	removedMissile.push_back(sprite);
}

void GameSession::addShield(std::shared_ptr<Sprite> sprite) {
	addedShields.push_back(sprite);
}

void GameSession::removeShield(std::shared_ptr<Sprite> sprite) {
	removedShields.push_back(sprite);
}

void GameSession::run() {
	bool quit = false;
	Uint32 tickInterval = 1000 / FPS;
	score = 0;

	while (!quit) {   //Yttre while
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {  //innre While
			switch (event.type)
			{
			case SDL_QUIT: quit = true; break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
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
				case SDLK_UP:
					std::cout << "Up arrow pushed\n";
					for (auto s : sprites) {
						s->upButton();
					}
					break;
				case SDLK_DOWN:
					std::cout << "Down arrow pushed\n";
					for (auto s : sprites) {
						s->downButton();
					}
					break;
				case SDLK_SPACE:
					std::cout << "Spacebar pushed\n";
					for (auto s : sprites) {
						s->spaceBar(missiles.size());
					}
					break;
				}//switch event.key.keysym.sym
			}//switch event.type
		}//Innre While

		for (auto s : sprites) {
			quit = s->tick(sprites);
			if (quit) {
				break;
			}
		}
		
		for (auto s : missiles) {
			score += (s->tick(sprites));
		}

		//add sprites 
		for (auto s : added) {
			sprites.push_back(s);
		}
		added.clear();

		//remove sprites
		for (auto s : removed)
			for (auto i = sprites.begin(); i != sprites.end();)
				if (*i == s) {
					i = sprites.erase(i);
				}
				else {
					i++;
				}
		removed.clear();

		//add missiles
		for (auto s : addedMissile) {
			missiles.push_back(s);
		}
		addedMissile.clear();

		//remove missiles
		for (auto s : removedMissile)
			for (auto i = missiles.begin(); i != missiles.end();)
				if (*i == s) {
					i = missiles.erase(i);
				}
				else {
					i++;
				}
		removedMissile.clear();

		SDL_SetRenderDrawColor(sys.ren, 0, 0, 0, 0);
		SDL_RenderClear(sys.ren);
		for (auto sprite : sprites) {
			sprite->draw(score);
		}

		for (auto missile : missiles) {
			missile->draw(score);
		}
		
		SDL_RenderPresent(sys.ren);

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}//Yttre run loop
}
