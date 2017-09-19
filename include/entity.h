#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <SFML/Graphics.hpp>
#include "scene_node.h"

class Entity : public SceneNode
{
    public:
        void setVelocity(const sf::Vector2f &velocity);
        void setVelocity(const float &vx, const float &vy);
        sf::Vector2f getVelocity() const;

    private:
        virtual void updateCurrent(sf::Time dt);

    private:
        sf::Vector2f mVelocity;
};

#endif
