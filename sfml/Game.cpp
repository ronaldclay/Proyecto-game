#include "Game.h"
const float Game::PlayerSpeed = 100.f;
Game::Game() : mWindow(sf::VideoMode(640, 480), "JUEGO")
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingRight(false)
, mIsMovingLeft(false)
,mTexture()
, mPlayer() {
	
	if (!mTexture.loadFromFile("C:\\Users\\user\\Downloads\\Juego\\juego\\juego\\Nave.png")) {

	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(300.f,325.f);
	mPlayer.setScale(0.3,0.3);

}

void Game::run()
{
	sf::Clock clock;
	while (mWindow.isOpen()) {
		sf::Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();

	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{


		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;
	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();	
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}
