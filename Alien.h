#ifndef ALIEN_H
#define ALIEN_H

#include "Sprite.h"
#include "System.h"
#include "GameSession.h"
#include "AlienBomb.h"

#include <SDL_image.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Alien : public Sprite
{
public:
	static shared_ptr<Alien> getInstance(int x, int y, string image, int hitScore = 0);
	void draw(int score);
	int tick(const vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession);
	int hit();

	~Alien();

private:
	Alien(int x, int y, std::string image, int hS);

	SDL_Texture* alienTexture;
	bool movingRight = true;
	int pos = 0, hitScore;
};
#endif

