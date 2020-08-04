#ifndef _GAME_H_
#define _GAME_H_

#include "MainMenuState.h"

class Game
{
private:
	sf::RenderWindow *		   window = nullptr;
	sf::Event				      sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings		   windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float		 dt;

	std::stack<State *> states;
	
	std::map<std::string, int> supportedKeys;

	// Initializing
	void initVaritales();
	void initWindow();
	void initStates();
	void initKeys();

public:
	Game();
	virtual ~Game();

	// Functions
	void endApplication();

	// Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	// Render
	void render();

	// Core
	void run();
};
#endif // !_GAME_H
