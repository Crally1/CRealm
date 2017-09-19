#ifndef _SPRITE_NODE_H_
#define _SPRITE_NODE_H_

#include "scene_node.h"
#include <SFML/Graphics.hpp>

class SpriteNode : public SceneNode
{
    public:
        explicit SpriteNode(const sf::Texture &texture);
        SpriteNode(const sf::Texture &texture, const sf::IntRect& rect);

    private:
<<<<<<< HEAD
        virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
=======
        virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates) const;
>>>>>>> f035394a846f3cc9eb916888ddb2634817cf18bc

    private:
        sf::Sprite mSprite;
};

#endif
