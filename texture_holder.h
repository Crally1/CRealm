#ifndef _TEXTURE_HOLDER_H_
#define _TEXTURE_HOLDER_H_


#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Texture
{
    enum ID
    {
        PLAYER, MAP, BAXKGROUND
    };
}

class TextureHolder
{
    public:
        void load(Texture::ID id, const std::string &fileName);
        sf::Texture& get(Texture::ID id);
        const sf::Texture& get(Texture::ID id) const;


    private:
        std::map<Texture::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

#endif
