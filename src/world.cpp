#include "world.h"

World::World(sf::RenderWindow &window) :mWindow(window), 
    mWorldView(window.getDefaultView()),
    mTextures(),
    mSceneGraph(),
    mSceneLayers(),
    mWorldBounds(0.0f, 0.0f, mWorldView.getSize().x, 2000.0f),
    mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f), 
    mScrollSpeed(-50.0f),
    mPlayerEntity(nullptr)
{
    loadTextures();
    buildScene();

    mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures()
{
    mTextures.load(Texture::MAP, "/home/crally/CRealm/assets/sprites.png", sf::IntRect(192, 576, 32, 32));
    mTextures.load(Texture::PLAYER, "/home/crally/CRealm/assets/sprites.png", sf::IntRect(864, 160, 32, 32));
}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt)
{
    mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

    sf::Vector2f position = mPlayerEntity->getPosition();
    sf::Vector2f velocity = mPlayerEntity->getVelocity();

    if (position.x <= mWorldBounds.left + 150.f || position.x >= mWorldBounds.left + mWorldBounds.width - 150.0f)
    {
        velocity.x = -velocity.x;
        mPlayerEntity->setVelocity(velocity);
    }

    mSceneGraph.update(dt);
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
    mPlayerEntity->setVelocity(40.0f, mScrollSpeed);
    mPlayerEntity->setScale(2.2f, 2.2f);
    mSceneLayers[Foreground]->addChild(std::move(leader));
}
