#include "scene_node.h"

SceneNode::SceneNode() : mParent(nullptr), mChildren()
{
    //Not sure we need to do much else in the constructor,
    //mParent should be set when adding children nodes.
}

void SceneNode::addChild(std::unique_ptr<SceneNode> node)
{
    node->mParent = this;
    mChildren.push_back(std::move(node));
}

std::unique_ptr<SceneNode> SceneNode::delChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
            [&](std::unique_ptr<SceneNode> &p) -> bool { return p.get() == &node; });

    assert(found != mChildren.end());

    std::unique_ptr<SceneNode> res = std::move(*found);
    res->mParent = nullptr;
    mChildren.erase(found);

    return res;
}

void SceneNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    states.transform *= getTransform();

    drawCurrent(window, states);
    drawChildren(window, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &window, sf::RenderStates states) const
{
    //Do nothing by default
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto &child : mChildren)
    {
        child->draw(target, states);
    }
}

void SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
    //Do nothing by default
}

void SceneNode::updateChildren(sf::Time dt)
{
    for (const auto &node : mChildren)
    {
        node->update(dt);
    }
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode* node = this; node != nullptr; node = node->mParent)
    {
        transform = node->getTransform() * transform;
    }

    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}
