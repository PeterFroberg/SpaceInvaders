
#include "GameSession.h"
#include "Alien.h"
#include "Shield.h"
#include "Score.h"
#include "Ship.h"
#include "Missile.h"
#include "AlienBomb.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <string>
#include <cstring>
#include <memory>
#include <typeinfo>


//#include <iostream>

using namespace std;

//class AlienBomb;
class Ship;
class Shield;

GameSession gameSession;

int main(int argc, char** argv) {
	std::vector<string> galaxians_images = { "space-invaders-galaxian1.png" , "space-invaders_galaxian2.png", "space-invaders_galaxian3.png", "space-invaders-galaxian4.png", "space-invaders-galaxian4.png" };
	int col = 10;
	int row = 70;
	for (int g = 0; g < 5; g++) {
		for (int i = 0; i < 10; i++) {
			gameSession.add(Alien::getInstance(col, row, galaxians_images[g], (g + 1) * 10));
			col += 50;
		}
		col = 10;
		row += 50;
	}

	col = 75;
	row = 575;
	for (int i = 0; i < 4; i++) {
		gameSession.add(Shield::getInstance(col, row, 60, 60, "spaceinvaders_shield.PNG"));
		col += 150;
	}

	gameSession.add(Ship::getInstance("Spaceship.PNG"));
	gameSession.add(Score::getInstance(300, 15, 150, 40, "Score: "));
	gameSession.run(60, &gameSession);
	AlienBomb::freeAlienChunk();
	Missile::free_missile_chunk();
	return 0;
}
