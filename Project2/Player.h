#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"

class Player :
    public Entity
{
private:
    // Variables

    // Initializer functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture & texture);
    virtual ~Player();

    // Functions
};
#endif // !_PLAYER_H
