#ifndef MISSILE_H
#define MISSILE_H

#include "Sprite.h"
#include "System.h"
#include "GameSession.h"
#include "Alien.h"
#include "Shield.h"
#include <SDL_image.h>

using namespace std;

class Missile :	public Sprite, public enable_shared_from_this<Missile>
{
public:
	static shared_ptr<Missile> getInstance(int x, int y, std::string image);
	static void free_missile_chunk();
	void draw(int score);
	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession);
	~Missile();


private:
	SDL_Texture* texture;
	static Mix_Chunk* missileHit;

	Missile(int x, int y, std::string image);
	bool checkCollision(std::shared_ptr<Sprite> s);

};

#endif // !MISSILE_H
