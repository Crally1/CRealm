#ifndef _WORLD_H_
#define _WORLD_H_

#include "texture_holder.h"
#include "player_entity.h"
#include <SFML/Graphics.hpp>
#include "sprite_node.h"


class World : private sf::NonCopyable
{
    public:
        explicit World(sf::RenderWindow &window);
        void update(sf::Time dt);
        void draw();

    private:
        void loadTextures();
        void buildScene();

    private:
        enum Layer
        {
            Background,
            Foreground,
            LayerCount
        };

    private:
        sf::RenderWindow &mWindow;
        sf::View mWorldView;
        TextureHolder mTextures;
        SceneNode mSceneGraph;
        std::array<SceneNode*, LayerCount> mSceneLayers;
        
        sf::FloatRect mWorldBounds;
        sf::Vector2f mSpawnPosition;
        float mScrollSpeed;
        Player* mPlayerEntity;
};

#endif
