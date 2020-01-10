#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL.h>
#include <vector>
#include <memory>

class GameSession;

class Sprite
{
public:
	virtual void keyDown(SDL_Keycode k, int numberOfMissiles, GameSession* gameSession) {}
	virtual void keyUp(SDL_Keycode k, int numberOfMissiles, GameSession* gameSession) {}
	virtual void spaceBar(int nuberOfMissiles, GameSession* gameSession) {}
	virtual void leftButton() {}
	virtual void rightButton() {}
	virtual void draw(int score) = 0;
	SDL_Rect getRect() const { return rect; }
	SDL_Rect setRect(int x, int y, int w, int h) { rect.x = x, rect.y = y, rect.w = w; rect.h = h; return rect; }
	virtual int tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession) = 0;
	virtual int hit() { return -1; }
	virtual ~Sprite() {}

protected:
	Sprite(int x, int y, int w, int h, std::string image) : rect{ x,y,w,h } {}
	SDL_Rect rect;

private:
	Sprite(const Sprite& other) = delete; //tar bort copy-constructor
	const Sprite& operator = (const Sprite& other) = delete;   //tar bort tilldelnings konstruktor
};

#endif