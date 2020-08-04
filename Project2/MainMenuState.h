#ifndef _MAIN_MENU_STATE
#define _MAIN_MENU_STATE

#include "GameState.h"
#include "Button.h"

class MainMenuState :
	public State
{
private:
	// Variables
	sf::Texture        backgroundTexture;
	sf::RectangleShape background;
	sf::Font           font;

	//Button * gamestate_btn;
	std::map<std::string, Button *> buttons;

	// Functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int> * supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	// Functions
	void endState();

	// Update
	void updateInput(const float & dt);
	void updateButtons(sf::RenderTarget* target = nullptr);
	void update(const float & dt);
	void renderButtons(sf::RenderTarget* target);

	// Render
	void render(sf::RenderTarget * target = nullptr);

};
#endif // !_MAIN_MENU_STATE



