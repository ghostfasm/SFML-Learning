#ifndef _STATE_H
#define _STATE_H

#include "Player.h"

class State
{
private:

protected:
	std::stack<State *> *        states;
	sf::RenderWindow *           window;
	std::map<std::string, int> * supportedKeys;
	std::map<std::string, int>   keybinds;

	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Resources
	std::map<std::string, sf::Texture> textures;

	// Functions
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow * window, std::map<std::string, int> * supportedKeys, std::stack<State*>* states);
	virtual ~State();

	// Functions
	const bool & getQuit() const;
	
    void endState();

	// Update
	virtual void updateMousePositions();

	virtual void updateInput(const float & dt) = 0;
	virtual void update(const float & dt)      = 0;

	// Render
	virtual void render(sf::RenderTarget * target = nullptr) = 0;
};

#endif // !_STATE_H


