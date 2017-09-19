#include "sprite_node.h"

SpriteNode::SpriteNode(const sf::Texture &texture, const sf::IntRect &rect) : mSprite(texture)
{

}

void SpriteNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
