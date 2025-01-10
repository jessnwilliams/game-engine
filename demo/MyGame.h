#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

#include "../engine/AbstractGame.h"

struct GameKey {
	Point2 pos;
	bool isAlive;
};

class MyGame : public AbstractGame {
	private:
		
		Rect box;
		Rect btn;
		Rect box1;
		Rect box2;
		Rect box3;
		Rect bxtxt;
		Rect sldrbx;
		Rect sldrbx1;
		Rect sldrbx2;
		Rect sldrbx3;
		Rect sldrbx4;
		Rect sldrbx5;
		Rect charCard;

		SDL_Texture* image;
		SDL_Texture* image2;
		SDL_Texture* imgGhostR;
		SDL_Texture* imgGhostB;
		SDL_Texture* imgPacman;
		SDL_Texture* imgGhostO;
		SDL_Texture* imgGhostP;
		SDL_Texture* imgToDisplay;
		SDL_Texture* blinkyCC;
		SDL_Texture* inkyCC;
		SDL_Texture* pacMCC;
		SDL_Texture* pinkyCC;
		SDL_Texture* clydeCC;
		SDL_Texture* imgTXT;

		

		Vector2i velocity;

		std::vector<std::shared_ptr<GameKey>> gameKeys;

		/* GAMEPLAY */
		int score, numKeys, lives;
		int counter;
		bool gameWon;

		void handleKeyEvents();
		void update();
		void render();
		void renderUI();
	public:
        MyGame();
		~MyGame();
};

#endif