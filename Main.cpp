
#include "GameSession.h"
#include "Alien.h"
#include "Shield.h"
#include "Score.h"
#include "Ship.h"
//#include "System.h"
//#include "Sprite.h"
#include "Missile.h"
#include "AlienBomb.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <string>
#include <cstring>
#include <memory>
#include <typeinfo>


//#include <iostream>

using namespace std;

//class AlienBomb;
class Ship;
class Shield;

GameSession gameSession;

//class AlienBomb1 : public Sprite, public enable_shared_from_this<AlienBomb> {
//public:
	//static shared_ptr<AlienBomb> getInstance(int x, int y, std::string image) {
	//	return shared_ptr<AlienBomb>(new AlienBomb(x, y, image));
	//}

	//static void free_alien_chnuk() {
	//	Mix_FreeChunk(alienBombHit);
	//}

	//void draw(int score) {
	//	SDL_RenderCopy(sys.ren, alienBombTexture, NULL, &getRect());
	//}

	//int tick(const std::vector<std::shared_ptr<Sprite>>& sprites) {

	//	if (rect.y >= 690) {
	//		gameSession.remove(shared_from_this());
	//	}
	//	else
	//	{
	//		rect.y += 3;
	//	}
	//	for (std::shared_ptr<Sprite> s : sprites) {  //Kontrollera missilträffar	
	//		std::shared_ptr<Ship> ship;
	//		std::shared_ptr<Shield> sh;

	//		if ((ship = dynamic_pointer_cast<Ship> (s)) || (sh = dynamic_pointer_cast<Shield> (s))) {
	//			if (checkCollision(s)) {
	//				gameSession.remove(shared_from_this());
	//				if (ship) {
	//					gameSession.remove(s);
	//					return 999; //end game
	//				}
	//				if (s->hit() == -1) {
	//					gameSession.remove(s);
	//				}

	//			}
	//		}
	//	}

	//	return 0;
	//}

	//
	//
	//~AlienBomb() {
	//	SDL_DestroyTexture(alienBombTexture);
	//	//Mix_FreeChunk(alienBombHit);
	//}
//private:
	//SDL_Texture* alienBombTexture;
	//static Mix_Chunk* alienBombHit;

	/*AlienBomb(int x, int y, std::string image) : Sprite(x, y, 5, 20, image) {
		alienBombTexture = IMG_LoadTexture(sys.ren, image.c_str());
		alienBombHit = Mix_LoadWAV("explosion.wav");
	}

	bool checkCollision(std::shared_ptr<Sprite> s) {
		if (rect.x + rect.w < s->getRect().x ||
			rect.x > s->getRect().x + s->getRect().w ||
			rect.y + rect.h < s->getRect().y ||
			rect.y > s->getRect().y + s->getRect().h)
		{
			return false;
		}
		Mix_PlayChannel(-1, alienBombHit, 0);
		return true;
	}*/
//};

//class Alien1 : public Sprite {
//public:
	/*static shared_ptr<Alien> getInstance(int x, int y, std::string image, int hitScore = 0) {
		return shared_ptr<Alien>(new Alien(x, y, image, hitScore));
	}
	
	void draw(int score) {
		SDL_RenderCopy(sys.ren, alienTexture, NULL, &getRect());
	}
	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites) {
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
			gameSession.add(AlienBomb::getInstance(rect.x, rect.y, "bomb.png"));
		}
		return 1;
	}
	int hit() {
		return hitScore;
	}

	~Alien() {
		SDL_DestroyTexture(alienTexture);
	}*/

//private:
	/*SDL_Texture* alienTexture;
	bool movingRight = true;
	int pos = 0, hitScore;*/

	/*Alien(int x, int y, std::string image, int hS) : Sprite(x, y, 30, 30, image) {
		alienTexture = IMG_LoadTexture(sys.ren, image.c_str());
		hitScore = hS;
	}*/
//};

//class Shield1 : public Sprite {
//public:
//	static shared_ptr<Shield> getInstance(int x, int y, int w, int h, std::string image) {
//		return shared_ptr<Shield>(new Shield(x, y, w, h, image));
//	}
//
//	void draw(int score) {
//		SDL_RenderCopy(sys.ren, shieldTexture, NULL, &getRect());
//	}
//
//	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites) {
//		return 0;
//	}
//
//	int hit() {
//		setRect(getRect().x + ((getRect().w * 0.1) / 2), getRect().y + ((getRect().h * 0.1) / 2), getRect().w * 0.9, getRect().h * 0.9);
//		hitcount--;
//		if (hitcount > 0) {
//			return false;
//		}
//		return -1;
//	}
//
//	~Shield() {
//		SDL_DestroyTexture(shieldTexture);
//	}
//
//private:
//	SDL_Texture* shieldTexture;
//	int hitcount = 0;
//	Shield(int x, int y, int w, int h, std::string image) : Sprite(x, y, w, h, image) {
//		shieldTexture = IMG_LoadTexture(sys.ren, image.c_str());
//		hitcount = 5;
//	}
//};



//class Missile1 : public Sprite, public enable_shared_from_this<Missile> {
//public:
//	static shared_ptr<Missile> getInstance(int x, int y, std::string image) {
//		return shared_ptr<Missile>(new Missile(x, y, image));
//	}
//
//	void draw(int score) {
//		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
//	}
//	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites) {
//
//		if (rect.y <= 0) {
//			gameSession.removeMissile(shared_from_this());
//		}
//		else //if (counter % 10 == 0)
//		{
//			rect.y -= 4;
//		}
//
//		for (std::shared_ptr<Sprite> s : sprites) {  //Kontrollera missilträffar	
//			std::shared_ptr<Alien> a;
//			std::shared_ptr<Shield> sh;
//			if ((a = dynamic_pointer_cast<Alien> (s)) || (sh = dynamic_pointer_cast<Shield> (s))) {
//				if (checkCollision(s)) {
//					gameSession.removeMissile(shared_from_this());
//					if (a) {
//						gameSession.remove(s);
//						return s->hit();
//					}
//					if (s->hit() == -1) {
//						gameSession.remove(s);
//					}
//				}
//			}
//		}
//		return 0;
//	}
//
//	~Missile() {
//		SDL_DestroyTexture(texture);
//	}
//
//private:
//	SDL_Texture* texture;
//	Mix_Chunk* missileHit;
//
//	Missile(int x, int y, std::string image) : Sprite(x, y, 5, 20, image) {
//		texture = IMG_LoadTexture(sys.ren, image.c_str());
//		missileHit = Mix_LoadWAV("invaderkilled.wav");
//	}
//
//	bool checkCollision(std::shared_ptr<Sprite> s) {
//		if (rect.x + rect.w < s->getRect().x ||
//			rect.x > s->getRect().x + s->getRect().w ||
//			rect.y + rect.h < s->getRect().y ||
//			rect.y > s->getRect().y + s->getRect().h)
//		{
//			return false;
//		}
//		Mix_PlayChannel(-1, missileHit, 0);
//		return true;
//	}
//};


//class Score1 : public Sprite
//{
//public:
//	static shared_ptr<Score> getInstance(int x, int y, int w, int h, std::string txt1) {
//		return shared_ptr<Score>(new Score(x, y, w, h, txt1));
//	}
//
//	void draw(int score) {
//		std::string newScore = std::to_string(score);
//		setScore(newScore);
//		SDL_RenderCopy(sys.ren, scoreTexture, NULL, &getRect());
//	}
//
//	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites) {
//		return 0;
//	}
//
//	void setScore(std::string txt) {
//		std::string newText = scoreText + txt;
//		SDL_Surface* surf = TTF_RenderText_Solid(sys.font, newText.c_str(), { 255, 255, 255 });
//		SDL_DestroyTexture(scoreTexture);
//		scoreTexture = SDL_CreateTextureFromSurface(sys.ren, surf);
//		SDL_FreeSurface(surf);
//	}
//
//	~Score() {
//		SDL_DestroyTexture(scoreTexture);
//	}
//
//private:
//	SDL_Texture* scoreTexture;
//	std::string scoreText;
//
//	Score(int x, int y, int w, int h, std::string txt) : Sprite(x, y, w, h, txt) {
//		scoreText = txt;
//		SDL_Surface* surf = TTF_RenderText_Solid(sys.font, txt.c_str(), { 255,255,255 });
//		SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(sys.ren, surf);
//		SDL_FreeSurface(surf);
//	}
//};


//class Ship1 : public Sprite {
//public:
//	static shared_ptr<Ship> getInstance(std::string image) {
//		return shared_ptr<Ship>(new Ship(image));
//	}
//	
//	void draw(int score) {
//		SDL_RenderCopy(sys.ren, shipTexture, NULL, &getRect());
//	}
//	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites) { 
//		return 0; 
//	}
//	void leftButton() {
//		rect.x -= 3;
//	}
//	void rightButton() {
//		rect.x += 3;
//	}
//	void spaceBar(int numberOfMissiles) {		
//		if (numberOfMissiles < maxNumberOfMissiles) {
//			gameSession.addMissile(Missile::getInstance(rect.x + 20, rect.y - 10, "missile.png"), 1);
//			Mix_PlayChannel(-1, fireMissile, 0);
//		}
//	}
//
//	~Ship() {
//		SDL_DestroyTexture(shipTexture);
//		Mix_FreeChunk(fireMissile);
//	}
//	
//private:
//	int maxNumberOfMissiles = 1;
//	SDL_Texture* shipTexture;
//	Mix_Chunk* fireMissile;
//
//	Ship(std::string image) : Sprite(200, 650, 40, 40, image) {
//		shipTexture = IMG_LoadTexture(sys.ren, image.c_str());
//		fireMissile = Mix_LoadWAV("shoot.wav");
//	}
//};

int main(int argc, char** argv) {
	std::vector<std::string> galaxians_images = { "space-invaders-galaxian1.png" , "space-invaders_galaxian2.png", "space-invaders_galaxian3.png", "space-invaders-galaxian4.png", "space-invaders-galaxian4.png" };
	int col = 10;
	int row = 70;
	for (int g = 0; g < 5; g++) {
		for (int i = 0; i < 10; i++) {
			gameSession.add(Alien::getInstance(col, row, galaxians_images[g], (g+1) * 10));
			col += 50;
		}
		col = 10;
		row += 50;
	}

	col = 75;
	row = 575;
	for (int i = 0; i < 4; i++) {
		gameSession.add(Shield::getInstance(col, row, 60, 60, "spaceinvaders_shield.PNG"));
		col += 150;
	}

	gameSession.add(Ship::getInstance("Spaceship.PNG"));
	gameSession.add(Score::getInstance(300, 15, 150, 40,"Score: "));
	gameSession.run(60, &gameSession);
	AlienBomb::freeAlienChunk();
	Missile::free_missile_chunk();
	return 0;
}
