#ifndef GAMESESSION_H
#define GAMESESSION_H

#include "Sprite.h"
#include <vector>
#include <memory>

class GameSession
{
public:
	void add(std::shared_ptr<Sprite> sprite);
	void addMissile(std::shared_ptr<Sprite> sprite, const int maxNoMissiles);
	void removeMissile(std::shared_ptr<Sprite> sprite);
	void remove(std::shared_ptr<Sprite> sprite);
	void run();

	

protected:

private:
	std::vector<std::shared_ptr<Sprite>> sprites, missiles;
	std::vector<std::shared_ptr<Sprite>> added, removed, addedMissile, removedMissile;

	
};

#endif

