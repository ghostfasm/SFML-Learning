#include "Game.h"

Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

// Initializer functions
void Game::initVaritales()
{
    this->window     = nullptr;
    this->fullscreen = false;

    this->dt = 5.f;
}

void Game::initKeys()
{
    std::ifstream ifs("Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value   = 0;

        while (ifs >> key >> key_value)
        {
           this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

void Game::initWindow()
{
    std::ifstream ifs("Config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();
    sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();

    std::string title           = "None";
    bool fullscreen             = false;
    unsigned framerateLimit     = 120;
    bool verticalSyncEnabled    = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> fullscreen;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
        ifs >> antialiasing_level;
    }

    ifs.close();

    this->windowSettings.antialiasingLevel = antialiasing_level;
    this->fullscreen                       = fullscreen;
    
    if (this->fullscreen)
        this->window = new sf::RenderWindow(sf::VideoMode(windowBounds), title, sf::Style::Fullscreen, windowSettings);
    else
        this->window = new sf::RenderWindow(sf::VideoMode(windowBounds), title, sf::Style::Titlebar | sf::Style::Close, windowSettings);

    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

// Functions
void Game::endApplication()
{
    std::cout << "Ending Application!" << "\n";
}

// Update 
void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        this->states.top()->render(window);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Application end
    else
    { 
        this->endApplication();
        this->window->close();
    }
}

// Render
void Game::render()
{
    this->window->display();
    this->window->clear();
}

// Core
void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

