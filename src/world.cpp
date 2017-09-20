#include "world.h"

World::World(sf::RenderWindow &window) :mWindow(window), mWorldView(window.getDefaultView()),
    mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
    mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y), 
    mPlayerEntity(nullptr)
{
    loadTextures();
    buildScene();

    mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures()
{
    mTextures.load(Texture::MAP, "/home/crally/CRealm/assets/stone.jpeg");
    mTextures.load(Texture::PLAYER, "/home/crally/CRealm/assets/wizard.png");
}

void World::buildScene()
{
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        std::unique_ptr<SceneNode> layer(new SceneNode);
        mSceneLayers[i] = layer.get();

        mSceneGraph.addChild(std::move(layer));
    }

    sf::Texture &texture = mTextures.get(Texture::MAP);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);

    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
    mSceneLayers[Background]->addChild(std::move(backgroundSprite));

    std::unique_ptr<Player> leader(new Player(Texture::PLAYER, mTextures));
    mPlayerEntity = leader.get();
    mPlayerEntity->setPosition(mSpawnPosition);
    mPlayerEntity->setVelocity(40.f, mScrollSpeed);
    mSceneLayers[Foreground]->addChild(std::move(leader));
}
