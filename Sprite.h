#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL.h>
#include <vector>
#include <memory>

class Sprite
{
public:
	virtual void spaceBar(int nuberOfMissiles) {}
	virtual void leftButton() {}
	virtual void rightButton() {}
	virtual void draw() const = 0;
	SDL_Rect getRect() const { return rect; }
	virtual void tick(const std::vector<std::shared_ptr<Sprite>> &sprites) = 0;
	virtual void collisionDetection() {}
	virtual ~Sprite() {}

protected:
	Sprite(int x, int y, int w, int h, std::string image) : rect{ x,y,w,h } {}
	SDL_Rect rect;

private:

	const Sprite& operator = (const Sprite& other) = delete;
};

#endif