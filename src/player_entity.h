#ifndef _PLAYER_ENTITY_H_
#define _PLAYER_ENTITY_H_

#include "entity.h"
#include "texture_holder.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
    public:
        Player(Texture::ID id, TextureHolder &textures);
        virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        Texture::ID mType;
        sf::Sprite mSprite;
};

#endif
