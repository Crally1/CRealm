#ifndef _TEXTURE_HOLDER_H_
#define _TEXTURE_HOLDER_H_


#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Texture
{
    enum ID
    {
        PLAYER, MAP, BACKGROUND
    };
}

class TextureHolder
{
    public:
        void load(Texture::ID id, const std::string &fileName);
        void load(Texture::ID id, const std::string &fileName, const sf::IntRect &rect);
        sf::Texture& get(Texture::ID id);
        const sf::Texture& get(Texture::ID id) const;


    private:
        std::map<Texture::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

#endif
