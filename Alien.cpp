#include "Alien.h"

shared_ptr<Alien> Alien::getInstance(int x, int y, std::string image, int hitScore ) {
	return shared_ptr<Alien>(new Alien(x, y, image, hitScore));
}

void Alien::draw(int score) {
	SDL_RenderCopy(sys.ren, alienTexture, NULL, &getRect());
}
int Alien::tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession) {
	if (movingRight && pos < 200) {
		rect.x++;
		pos++;
		if (pos == 199) {
			movingRight = false;
		}
	}
	else {
		rect.x--;
		pos--;
		if (pos == 0) {
			movingRight = true;
		}
	}

	if ((rand() % 40000) < 10) {
		gameSession->add(AlienBomb::getInstance(rect.x, rect.y, "bomb.png"));
	}
	return 1;
}
int Alien::hit() {
	return hitScore;
}

Alien::~Alien() {
	SDL_DestroyTexture(alienTexture);
}
Alien::Alien(int x, int y, std::string image, int hS) : Sprite(x, y, 30, 30, image) {
	alienTexture = IMG_LoadTexture(sys.ren, image.c_str());
	hitScore = hS;
}
