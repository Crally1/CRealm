#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "texture_holder.h"
#include "scene_node.h"
#include "entity.h"
#include "player_entity.h"
#include "sprite_node.h"
#include "world.h"

class Game
{
    public:
        Game();
        void run();

    private:
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        void processEvents();
        void render();
        void update(sf::Time deltaTime);

    private:
        sf::RenderWindow mWindow;
        sf::Texture mTexture;
        sf::Sprite mSprite;
        World mWorld;
        sf::Time mTimePerFrame;
};

#endif
