#ifndef SHIP_H
#define SHIP_H

#include "Sprite.h"
#include "System.h"
#include "GameSession.h"
#include "Missile.h"

#include <SDL_mixer.h>

using namespace std;

class Ship : public Sprite
{
public:
	static shared_ptr<Ship> getInstance(std::string image);
	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession);
	void draw(int score);
	void keyDown(SDL_Keycode k, int numberOfMissiles, GameSession* gameSession);
	void leftButton();
	void rightButton();
	void spaceBar(int numberOfMissiles, GameSession* gameSession);
	~Ship();

private:
	int maxNumberOfMissiles = 1;
	SDL_Texture* shipTexture;
	Mix_Chunk* fireMissile;

	Ship(std::string image);
};

#endif // !SHIP_H