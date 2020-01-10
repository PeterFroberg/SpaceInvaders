#include "Missile.h"

Mix_Chunk* Missile::missileHit;

shared_ptr<Missile> Missile::getInstance(int x, int y, string image) {
	return shared_ptr<Missile>(new Missile(x, y, image));
}

void Missile::free_missile_chunk() {
	Mix_FreeChunk(missileHit);
}

void Missile::draw(int score) {
	SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
}
int Missile::tick(const vector<shared_ptr<Sprite>>& sprites, GameSession* gamesession) {

	if (rect.y <= 0) {
		gamesession->removeMissile(shared_from_this());
	}
	else
	{
		rect.y -= 4;
	}

	for (shared_ptr<Sprite> s : sprites) {  //Kontrollera missilträffar	
		shared_ptr<Alien> a;
		shared_ptr<Shield> sh;
		if ((a = dynamic_pointer_cast<Alien> (s)) || (sh = dynamic_pointer_cast<Shield> (s))) {
			if (checkCollision(s)) {
				gamesession->removeMissile(shared_from_this());
				if (a) {
					gamesession->remove(s);
					return s->hit();
				}
				if (s->hit() == -1) {
					gamesession->remove(s);
				}
			}
		}
	}
	return 0;
}

Missile::~Missile() {
	SDL_DestroyTexture(texture);
}

Missile::Missile(int x, int y, string image) : Sprite(x, y, 5, 20, image) {
	texture = IMG_LoadTexture(sys.ren, image.c_str());
	missileHit = Mix_LoadWAV("invaderkilled.wav");
}

bool Missile::checkCollision(shared_ptr<Sprite> s) {
	if (rect.x + rect.w < s->getRect().x ||
		rect.x > s->getRect().x + s->getRect().w ||
		rect.y + rect.h < s->getRect().y ||
		rect.y > s->getRect().y + s->getRect().h)
	{
		return false;
	}
	Mix_PlayChannel(-1, missileHit, 0);
	return true;
}
