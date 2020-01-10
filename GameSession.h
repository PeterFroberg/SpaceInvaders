#ifndef GAMESESSION_H
#define GAMESESSION_H

#include "Sprite.h"
#include <vector>
#include <memory>
#include "System.h"
#include <typeinfo>

using namespace std;

class GameSession
{
public:
	void add(std::shared_ptr<Sprite> sprite);
	void addMissile(std::shared_ptr<Sprite> sprite);
	void addShield(std::shared_ptr<Sprite> sprite);
	void removeMissile(std::shared_ptr<Sprite> sprite);
	void remove(std::shared_ptr<Sprite> sprite);
	void removeShield(std::shared_ptr<Sprite> sprite);
	void run(int fps, GameSession* gameSession);

protected:

private:
	int score;
	std::vector<std::shared_ptr<Sprite>> sprites, missiles, shields, added, removed, addedMissile, removedMissile, addedShields, removedShields;
};

#endif

