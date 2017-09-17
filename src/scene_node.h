#ifndef _SCENE_NODE_H_
#define _SCENE_NODE_H_

#include <vector>
#include <algorithm>
#include <memory>
#include <SFML/Graphics.hpp>
#include <cassert>

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
    public:
        SceneNode();
        void addChild(std::unique_ptr<SceneNode> node);
        std::unique_ptr<SceneNode> delChild(const SceneNode &node);

    private:
        virtual void Draw(sf::RenderTarget &window, sf::RenderStates states) const;
        virtual void DrawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        std::vector<std::unique_ptr<SceneNode>> mChildren;
        SceneNode *mParent;
};

#endif
