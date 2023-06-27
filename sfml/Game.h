#pragma once
#include <SFML/Graphics.hpp>


class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();
	static const float		PlayerSpeed;
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed); private:
	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingRight;
	bool					mIsMovingLeft;
private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::Texture mTexture;

};
