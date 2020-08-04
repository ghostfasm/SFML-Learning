#ifndef _MOVEMENT_COMPONENT_H
#define _MOVEMENT_COMPONENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

class MovementComponent
{
private:
    sf::Sprite & sprite;

    float maxVelocity;

    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f deceleration;


    // Initializer functions;

public:
    MovementComponent(sf::Sprite & sprite, float maxVelocity);
    virtual ~MovementComponent();

    // Accessors
    const sf::Vector2f & getVelocity() const;

    // Function
    void move(const float dir_x, const float dir_y, const float& dt);
    void update(const float x, const float y);
};

#endif