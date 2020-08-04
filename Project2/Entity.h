#ifndef _ENTITY_H
#define _ENTITY_H

#include "MovementComponent.h"

class Entity
{
private:
    void initVariables();

protected:
    sf::Sprite    sprite;

	MovementComponent * movementComponent;

public:
	Entity();
	virtual ~Entity();

    // Components functions
    void setTexture(sf::Texture & texture);
    void createMovementComponent(const float & maxVelocity,
        const float acceleration, const float deceleration);

	// Functions
    virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y, const float & dt);

	// Update
	virtual void update(const float & dt);

	// Render
	virtual void render(sf::RenderTarget * target);
};
#endif // !_ENTITY_H

