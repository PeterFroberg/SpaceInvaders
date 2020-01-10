#ifndef SCORE_H
#define SCORE_H

#include "Sprite.h"
#include "System.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

class Score : public Sprite
{
public:
	static shared_ptr<Score> getInstance(int x, int y, int w, int h, std::string txt1);
	void draw(int score);
	int tick(const std::vector<std::shared_ptr<Sprite>>& sprites, GameSession* gameSession);
	void setScore(std::string txt);
	~Score();

private:
	SDL_Texture* scoreTexture;
	std::string scoreText;

	Score(int x, int y, int w, int h, std::string txt);
};

#endif

