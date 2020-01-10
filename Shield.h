#ifndef SHIELD_H
#define SHIELD_H

#include "Sprite.h"
#include "System.h"
#include <SDL_image.h>

using namespace std;

class Shield : public Sprite
{
public:
	static shared_ptr<Shield> getInstance(int x, int y, int w, int h, string image);
	void draw(int score);
	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession);
	int hit();
	~Shield();

private:
	SDL_Texture* shieldTexture;
	int hitcount = 0;
	Shield(int x, int y, int w, int h, std::string image);
};

#endif // !SHIELD_H