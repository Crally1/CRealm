#include "texture_holder.h"

void TextureHolder::load(Texture::ID id, const std::string &fileName)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture);
    if (!texture->loadFromFile(fileName))
    {
        std::cout << "Unable to load from FILE: " << fileName << std::endl;
        throw std::runtime_error("ERROR: Could not load texture from file: " + fileName);
    }

    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

void TextureHolder::load(Texture::ID id, const std::string &fileName, const sf::IntRect &rect)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture);
    if (!texture->loadFromFile(fileName, rect))
    {
        std::cout << "Unable to load from FILE: " << fileName << std::endl;
        throw std::runtime_error("ERROR: Could not load texture from file: " + fileName);
    }

    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::get(Texture::ID id)
{
    auto found = mTextureMap.find(id);

    return *found->second; 
}

const sf::Texture& TextureHolder::get(Texture::ID id) const
{
    auto found = mTextureMap.find(id);

    return *found->second;
}
