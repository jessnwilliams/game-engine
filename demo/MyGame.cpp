#include "MyGame.h"

MyGame::MyGame() : AbstractGame(), score(0), lives(3), numKeys(17), gameWon(false), box(5, 5, 30, 30), btn(675, 530, 90, 40), box1(50, 100, 150, 200), 
box2(225, 70, 400, 260), box3(650, 100, 100, 200), bxtxt(275, 350, 300, 100), sldrbx(10, 475, 780, 100), sldrbx1(60, 490, 120, 75), sldrbx2(200, 490, 120, 75), sldrbx3(340, 490, 120, 75), sldrbx4(480, 490, 120, 75), sldrbx5(625, 490, 120, 75) {
	TTF_Font * font = ResourceManager::loadFont("res/fonts/arial.ttf", 32);

	gfx->useFont(font);
	gfx->setVerticalSync(true);

	counter = 0;

    for (int i = 0; i < numKeys; i++) {
        std::shared_ptr<GameKey> k = std::make_shared<GameKey>();
        k->isAlive = true;
        k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
        gameKeys.push_back(k);
    }
}

MyGame::~MyGame() {

}

void MyGame::handleKeyEvents() {
	int speed = 3;

	if (eventSystem->isPressed(Key::W)) {
		velocity.y = -speed;
	}

	if (eventSystem->isPressed(Key::S)) {
		velocity.y = speed;
	}

	if (eventSystem->isPressed(Key::A)) {
		velocity.x = -speed;
	}

	if (eventSystem->isPressed(Key::D)) {
		velocity.x = speed;
	}
}

void MyGame::update() {
	box.x += velocity.x;
	box.y += velocity.y;

	for (auto key : gameKeys) {
		if (key->isAlive && box.contains(key->pos)) {
			score += 50;
			key->isAlive = false;
			numKeys--;
		}
	}

	velocity.x = 0;
    velocity.y = 0;

	if (numKeys == 0) {
		gameWon = true;
	}

	

	if (eventSystem->isPressed(Mouse::BTN_LEFT)&& counter == 0)  {
		gfx->openWindow();
		counter = 1;
		image = ResourceManager::loadTexture("res/images/gameplay.gif", SDL_COLOR_AQUA);
		image2 = ResourceManager::loadTexture("res/images/scores.jpg", SDL_COLOR_AQUA);
		imgGhostR = ResourceManager::loadTexture("res/images/redG.jpg", SDL_COLOR_AQUA);
		imgGhostB = ResourceManager::loadTexture("res/images/blueG.jpg", SDL_COLOR_AQUA);
		imgPacman = ResourceManager::loadTexture("res/images/pacman.jpg", SDL_COLOR_AQUA);
		imgGhostO = ResourceManager::loadTexture("res/images/orangeG.jpg", SDL_COLOR_AQUA);
		imgGhostP= ResourceManager::loadTexture("res/images/pinkG.jpg", SDL_COLOR_AQUA);

		
	}
}

void MyGame::render() {
	gfx->setDrawColor(SDL_COLOR_PINK);
	gfx->drawRect(box);

	gfx->setDrawColor(SDL_COLOR_ORANGE);
	for (auto key : gameKeys)
        if (key->isAlive)
		    gfx->drawCircle(key->pos, 5);
	
		
		if (eventSystem->isPressed(Mouse::BTN_LEFT)) {
			Point2 MousePos = eventSystem->getMousePos();

			if (MousePos.x > 60 && 765 > MousePos.x
				&& MousePos.y > 490 && 570 > MousePos.y) {
				gfx->drawText2("Blinky", 650, 100);
			}
		}
		else if (eventSystem->isPressed(Mouse::BTN_LEFT)) {
			Point2 MousePos = eventSystem->getMousePos();

			if (MousePos.x > 200 && 765 > MousePos.x
				&& MousePos.y > 490 && 570 > MousePos.y) {
				gfx->drawText2("Inky", 650, 100);
			}
		}
		else if (eventSystem->isPressed(Mouse::BTN_LEFT)) {
			Point2 MousePos = eventSystem->getMousePos();

			if (MousePos.x > 340 && 765 > MousePos.x
				&& MousePos.y > 490 && 570 > MousePos.y) {
				gfx->drawText2("PACMAN", 650, 100);
			}
		}
		else if (eventSystem->isPressed(Mouse::BTN_LEFT)) {
			Point2 MousePos = eventSystem->getMousePos();

			if (MousePos.x > 480 && 765 > MousePos.x
				&& MousePos.y > 490 && 570 > MousePos.y) {
				gfx->drawText2("Clyde", 650, 100);
			}
		}
		
		 if (eventSystem->isPressed(Mouse::BTN_LEFT)) {
			Point2 MousePos = eventSystem->getMousePos();
			if (MousePos.x > 625 && 765 > MousePos.x
				&& MousePos.y > 490 && 570 > MousePos.y) {
				gfx->drawText2("Pinky", 650, 100);
			}
		}
//675, 530, 90, 40
		//gfx->drawText("End Game", 250, 500);
	
}

void MyGame::renderUI() {
	gfx->setDrawColor(SDL_COLOR_GREEN);
	std::string scoreStr = std::to_string(score);
	gfx->drawText(scoreStr, 780 - scoreStr.length() * 50, 25);
	gfx->drawRect(btn);
	gfx->drawText("Quit", 685, 530);
	if (gameWon)
		gfx->drawText("YOU WON", 250, 500);
	gfx->setDrawColor(SDL_COLOR_PINK);
	gfx->drawRect2(box1);
	gfx->drawRect2(box2);
	gfx->drawRect2(box3);
	gfx->drawRect2(bxtxt);
	gfx->drawRect2(sldrbx1);
	gfx->drawRect2(sldrbx2);
	gfx->drawRect2(sldrbx3);
	gfx->drawRect2(sldrbx4);
	gfx->drawRect2(sldrbx5);
	gfx->drawText2("SDL GAME MENU", 100, 10);
	SDL_Rect rectangle = { 225, 70, 400, 260 };
	SDL_Rect rectangle2 = { 50, 100, 150, 200 };
	SDL_Rect rectGred = { 60, 490, 120, 75 };
	SDL_Rect rectGblue = { 200, 490, 120, 75 };
	SDL_Rect rectPacman= { 340, 490, 120, 75 };
	SDL_Rect rectGorange = { 480, 490, 120, 75 };
	SDL_Rect rectGpink = { 625, 490, 120, 75 };
	
	gfx->drawTexture2(image, &rectangle);
	gfx->drawTexture2(image2, &rectangle2);
	gfx->drawTexture2(imgGhostR, &rectGred);
	gfx->drawTexture2(imgGhostB, &rectGblue);
	gfx->drawTexture2(imgPacman, &rectPacman);
	gfx->drawTexture2(imgGhostO, &rectGorange);
	gfx->drawTexture2(imgGhostP, &rectGpink);
	
	

}