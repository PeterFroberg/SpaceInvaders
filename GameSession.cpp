#include "GameSession.h"
#include <SDL.h>

#include <iostream> //Only for debbuging ska tas bort

void GameSession::add(shared_ptr<Sprite> sprite) {
	added.push_back(sprite);
}

void GameSession::remove(shared_ptr<Sprite> sprite) {
	removed.push_back(sprite);
}

void GameSession::addMissile(shared_ptr<Sprite> sprite){ 
		addedMissile.push_back(sprite);
}

void GameSession::removeMissile(shared_ptr<Sprite> sprite) {
	removedMissile.push_back(sprite);
}

void GameSession::addShield(shared_ptr<Sprite> sprite) {
	addedShields.push_back(sprite);
}

void GameSession::removeShield(shared_ptr<Sprite> sprite) {
	removedShields.push_back(sprite);
}

void GameSession::run(int fps, GameSession* gameSession) {
	score = 0;
	bool quit = false;
	int numberOfAliensLeft = 0;
	Uint32 tickInterval = 1000 / fps;
	score = 0;

	while (!quit) {   //Yttre while
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {  //innre While
			switch (event.type)
			{
			case SDL_QUIT: quit = true; break;
			case SDL_KEYDOWN:
				for (auto s : sprites) {
					s->keyDown(event.key.keysym.sym, missiles.size(), gameSession);
				}
				break;
			case SDL_KEYUP:
				for (auto s : sprites) {
					s->keyUp(event.key.keysym.sym, missiles.size(), gameSession);
				}
			}//switch event.type
		}//Innre While

		//add sprites 
		for (auto s : added) {
			sprites.push_back(s);
		}
		added.clear();

		numberOfAliensLeft = 0;
		for (auto s : sprites) {
			numberOfAliensLeft += s->tick(sprites,gameSession);		
		}
		if (numberOfAliensLeft == 0 || numberOfAliensLeft >= 999) {
			quit = true;
			break;
		}
		
		for (auto s : missiles) {
			score += (s->tick(sprites, gameSession));
		}

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
