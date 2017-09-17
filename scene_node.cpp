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

void SceneNode::Draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (const auto &node : mChildren)
    {
        node->draw(window, states);
    }
}

void SceneNode::DrawCurrent(sf::RenderTarget &window, sf::RenderStates states) const
{

}
