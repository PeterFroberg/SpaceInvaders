#include "AlienBomb.h"

Mix_Chunk* AlienBomb::alienBombHit;

shared_ptr<AlienBomb> AlienBomb::getInstance(int x, int y, std::string image) {
	return shared_ptr<AlienBomb>(new AlienBomb(x, y, image));
}

void AlienBomb::freeAlienChunk() {
	Mix_FreeChunk(alienBombHit);
}

void AlienBomb::draw(int score) {
	SDL_RenderCopy(sys.ren, alienBombTexture, NULL, &getRect());
}

int AlienBomb::tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession) {

	if (rect.y >= 690) {
		gameSession->remove(shared_from_this());
	}
	else
	{
		rect.y += 3;
	}
	for (std::shared_ptr<Sprite> s : sprites) {  //Kontrollera missilträffar	
		std::shared_ptr<Ship> ship;
		std::shared_ptr<Shield> sh;

		if ((ship = dynamic_pointer_cast<Ship> (s)) || (sh = dynamic_pointer_cast<Shield> (s))) {
			if (checkCollision(s)) {
				gameSession->remove(shared_from_this());
				if (ship) {
					gameSession->remove(s);
					return 999; //end game
				}
				if (s->hit() == -1) {
					gameSession->remove(s);
				}

			}
		}
	}

	return 0;
}



AlienBomb::~AlienBomb() {
	SDL_DestroyTexture(alienBombTexture);
	//Mix_FreeChunk(alienBombHit);
}

AlienBomb::AlienBomb(int x, int y, std::string image) : Sprite(x, y, 5, 20, image) {
	alienBombTexture = IMG_LoadTexture(sys.ren, image.c_str());
	alienBombHit = Mix_LoadWAV("explosion.wav");
}

bool AlienBomb::checkCollision(std::shared_ptr<Sprite> s) {
	if (rect.x + rect.w < s->getRect().x ||
		rect.x > s->getRect().x + s->getRect().w ||
		rect.y + rect.h < s->getRect().y ||
		rect.y > s->getRect().y + s->getRect().h)
	{
		return false;
	}
	Mix_PlayChannel(-1, alienBombHit, 0);
	return true;
}