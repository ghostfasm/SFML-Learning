#ifndef _GAME_STATE_H
#define _GAME_STATE_H
#include "state.h"

class GameState :
	public State
{
private:
	Player * player;
	
	// Functions
	void initKeybinds();
    void initTextures();
    void initPlayers();

public:
	GameState(sf::RenderWindow * window, std::map<std::string, int> * supportedKeys, std::stack<State *> * states);
	virtual ~GameState();

	// Functions

	// Update
	void updateInput(const float & dt);
	void update(const float & dt);

	// Render
	void render(sf::RenderTarget * target = nullptr);

};

#endif // !_GAME_STATE_H
