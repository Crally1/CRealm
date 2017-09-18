#ifndef _SCENE_NODE_H_
#define _SCENE_NODE_H_

#include <vector>
#include <algorithm>
#include <memory>
#include <SFML/Graphics.hpp>
#include <cassert>

enum Layer
{
    Background,
    Foreground,
    LayerCouunt
};

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
    public:
        SceneNode();
        void addChild(std::unique_ptr<SceneNode> node);
        std::unique_ptr<SceneNode> delChild(const SceneNode &node);
        void update(sf::Time dt);
        sf::Vector2f getWorldPosition() const;

    private:
        virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
        virtual void updateCurrent(sf::Time dt);
        void updateChildren(sf::Time dt);
        sf::Transform getWorldTransform() const;

    private:
        std::vector<std::unique_ptr<SceneNode>> mChildren;
        SceneNode *mParent;
};

#endif
