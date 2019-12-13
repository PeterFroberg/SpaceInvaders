#ifndef GAMESESSION_H
#define GAMESESSION_H

#include "Sprite.h"
#include <vector>
#include <memory>

class GameSession
{
public:
	void add(std::shared_ptr<Sprite> sprite);
	void remove(std::shared_ptr<Sprite> sprite);
	void run();
	
protected:

private:
	std::vector<std::shared_ptr<Sprite>> sprites; 
	std::vector<std::shared_ptr<Sprite>> added, removed;
};

#endif

