#include "Score.h"

shared_ptr<Score> Score::getInstance(int x, int y, int w, int h, string txt1) {
	return shared_ptr<Score>(new Score(x, y, w, h, txt1));
}

void Score::draw(int score) {
	std::string newScore = to_string(score);
	setScore(newScore);
	SDL_RenderCopy(sys.ren, scoreTexture, NULL, &getRect());
}

int Score::tick(const vector<shared_ptr<Sprite>>& sprites, GameSession* gameSession) {
	return 0;
}

void Score::setScore(std::string txt) {
	string newText = scoreText + txt;
	SDL_Surface* surf = TTF_RenderText_Solid(sys.font, newText.c_str(), { 255, 255, 255 });
	SDL_DestroyTexture(scoreTexture);
	scoreTexture = SDL_CreateTextureFromSurface(sys.ren, surf);
	SDL_FreeSurface(surf);
}

Score::~Score() {
	SDL_DestroyTexture(scoreTexture);
}

Score::Score(int x, int y, int w, int h, string txt) : Sprite(x, y, w, h, txt) {
	scoreText = txt;
	SDL_Surface* surf = TTF_RenderText_Solid(sys.font, txt.c_str(), { 255,255,255 });
	SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(sys.ren, surf);
	SDL_FreeSurface(surf);
}