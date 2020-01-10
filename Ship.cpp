#include "Ship.h"

shared_ptr<Ship> Ship::getInstance(std::string image) {
	return shared_ptr<Ship>(new Ship(image));
}

void Ship::draw(int score) {
	SDL_RenderCopy(sys.ren, shipTexture, NULL, &getRect());
}
int Ship::tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gamesesion) {
	return 0;
}
void Ship::leftButton() {
	rect.x -= 3;
}
void Ship::rightButton() {
	rect.x += 3;
}
void Ship::spaceBar(int numberOfMissiles, GameSession* gameSession) {
	if (numberOfMissiles < maxNumberOfMissiles) {
		gameSession->addMissile(Missile::getInstance(rect.x + 20, rect.y - 10, "missile.png")); // , numberOfMissiles);
		Mix_PlayChannel(-1, fireMissile, 0);
	}
}

Ship::~Ship() {
	SDL_DestroyTexture(shipTexture);
	Mix_FreeChunk(fireMissile);
}

Ship::Ship(std::string image) : Sprite(200, 650, 40, 40, image) {
	shipTexture = IMG_LoadTexture(sys.ren, image.c_str());
	fireMissile = Mix_LoadWAV("shoot.wav");
}
