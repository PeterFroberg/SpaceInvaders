#ifndef ALIENBOMB_H
#define ALIENBOMB_H

#include "Sprite.h"
#include "System.h"
#include "GameSession.h"
#include "Shield.h"
#include "Ship.h"

#include <memory>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

using namespace std;

class AlienBomb : public Sprite, public enable_shared_from_this<AlienBomb>
{
public:
	static shared_ptr<AlienBomb> getInstance(int x, int y, std::string image);
	static void freeAlienChunk();
	void draw(int score);
	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession);

	bool checkCollision(std::shared_ptr<Sprite> s);

	~AlienBomb();

private:
	AlienBomb(int x, int y, std::string image);
	SDL_Texture* alienBombTexture;
	static Mix_Chunk* alienBombHit;
};
#endif

