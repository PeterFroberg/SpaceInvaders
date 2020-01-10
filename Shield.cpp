#include "Shield.h"

shared_ptr<Shield> Shield::getInstance(int x, int y, int w, int h, std::string image) {
	return shared_ptr<Shield>(new Shield(x, y, w, h, image));
}

void Shield::draw(int score) {
	SDL_RenderCopy(sys.ren, shieldTexture, NULL, &getRect());
}

int Shield::tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession) {
	return 0;
}

int Shield::hit() {
	setRect(getRect().x + ((getRect().w * 0.1) / 2), getRect().y + ((getRect().h * 0.1) / 2), getRect().w * 0.9, getRect().h * 0.9);
	hitcount--;
	if (hitcount > 0) {
		return false;
	}
	return -1;
}

Shield::~Shield() {
	SDL_DestroyTexture(shieldTexture);
}

Shield::Shield(int x, int y, int w, int h, std::string image) : Sprite(x, y, w, h, image) {
	shieldTexture = IMG_LoadTexture(sys.ren, image.c_str());
	hitcount = 5;
}