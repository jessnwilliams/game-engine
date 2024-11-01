#include "MyGame.h"

MyGame::MyGame() : AbstractGame(), score(0), lives(3), numKeys(17), gameWon(false), box(5, 5, 30, 30), btn(675, 530, 90, 40) {
	TTF_Font * font = ResourceManager::loadFont("res/fonts/arial.ttf", 32);
	gfx->useFont(font);
	gfx->setVerticalSync(true);

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
	if (eventSystem->isPressed(Mouse::BTN_LEFT)) {
		gfx->openWindow();
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

		if (MousePos.x > 675 && 765 > MousePos.x 
			&& MousePos.y > 530 && 570 > MousePos.y) {
			 gfx->drawText("End Game", 250, 500);
		}
//675, 530, 90, 40
		//gfx->drawText("End Game", 250, 500);
	}
}

void MyGame::renderUI() {
	gfx->setDrawColor(SDL_COLOR_GREEN);
	std::string scoreStr = std::to_string(score);
	gfx->drawText(scoreStr, 780 - scoreStr.length() * 50, 25);
	gfx->drawRect(btn);
	gfx->drawText("Quit", 685, 530);
	if (gameWon)
		gfx->drawText("YOU WON", 250, 500);
}