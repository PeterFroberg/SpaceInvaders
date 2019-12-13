
#include "GameSession.h"
#include "System.h"
#include "Sprite.h"
#include <SDL_image.h>
#include <vector>
#include <string>
#include <cstring>
#include <memory>

using namespace std;
//using namespace spaceInvaders

GameSession gameSession;

class Missile : public Sprite, public enable_shared_from_this<Missile>{
public:
	static shared_ptr<Missile> getInstance(int x, std::string image) {
		return shared_ptr<Missile>(new Missile(x, image));
	}

	Missile(int x, std::string image) : Sprite(x, 640, 5, 20, image) {
		texture = IMG_LoadTexture(sys.ren, image.c_str());
	}

	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	void tick() {
		counter++;
		if (rect.y <= 0) {
			gameSession.remove(shared_from_this());
		}
		else //if (counter % 10 == 0)
		{
			rect.y-=2;
		}
	}

	~Missile() {
		SDL_DestroyTexture(texture);
	}

private:
	SDL_Texture* texture;
	int counter = 0;
};

class Alien : public Sprite {
public:
	static shared_ptr<Alien> getInstance(int x, int y, std::string image) {
		return shared_ptr<Alien>(new Alien(x, y, image));
	}
	Alien(int x, int y, std::string image) : Sprite(x, y, 30, 30, image) {
		alienTexture = IMG_LoadTexture(sys.ren, image.c_str());
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, alienTexture, NULL, &getRect());
	}
	void tick() {
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
	}
	
private:
	SDL_Texture* alienTexture;
	bool movingRight = true;
	int pos = 0;
};

class Shield : public Sprite {
public:
	static shared_ptr<Shield> getInstance(int x, int y, std::string image) {
		return shared_ptr<Shield> (new Shield(x, y, image));
	}
	Shield(int x, int y, std::string image) : Sprite(x, y, 60, 60, image) {
		shieldTexture = IMG_LoadTexture(sys.ren, image.c_str());
	}

	void draw() const {
		SDL_RenderCopy(sys.ren, shieldTexture, NULL, &getRect());
	}

	void tick() {

	}

private:
	SDL_Texture* shieldTexture;
};

class Ship : public Sprite {
public:
	static shared_ptr<Ship> getInstance(std::string image) {
		return shared_ptr<Ship>(new Ship(image));
	}
	Ship(std::string image) : Sprite(200, 650, 40, 40, image) {
		shipTexture = IMG_LoadTexture(sys.ren, image.c_str());
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, shipTexture, NULL, &getRect());
	}
	void tick() {}
	void leftButton() {
		rect.x-=3;
	}
	void rightButton() {
		rect.x+=3;
	}
	void spaceBar() {
		//Missile* missile = Missile::getInstance(rect.x + 20, "missile.png");
		//gameSession.add(missile);
		gameSession.add(Missile::getInstance(rect.x + 20, "missile.png"));
	}
	
private:
	SDL_Texture* shipTexture;
};

int main(int argc, char** argv) {
	std::vector<std::string> galaxians_images = { "space-invaders-galaxian1.png" , "space-invaders_galaxian2.png", "space-invaders_galaxian3.png", "space-invaders-galaxian4.png", "space-invaders-galaxian4.png" };
	//Ship* ship = new Ship("SpaceShip.PNG");
	int col = 10;
	int row = 70;
	for (int g = 0; g < 5; g++) {
		for (int i = 0; i < 10; i++) {
			//Alien* alien = Alien::getInstance(col, row, galaxians_images[g]);
			//gameSession.add(alien);
			gameSession.add(Alien::getInstance(col, row, galaxians_images[g]));
			col += 50;
		}
		col = 10;
		row += 50;
	}

	col = 75;
	row = 575;
	for (int i = 0; i < 4; i++) {
		
		//Shield* shield = Shield::getInstance(col, row, "spaceinvaders_shield.PNG");
		//gameSession.add(shield);
		gameSession.add(Shield::getInstance(col, row, "spaceinvaders_shield.PNG"));
		col += 150;
	}

	gameSession.add(Ship::getInstance("Spaceship.PNG"));

	gameSession.run();
	return 0;
}