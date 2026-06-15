#include "resource.h"
#include <unordered_map>


//för att slippa ladda in textures om och om igen, kan anropas genom att tez: player.sprite.setTexture(Resource::get("assets/player.png"));
//kan clearas genom att Resource::clear();



static std::unordered_map<std::string, sf::Texture> texture_cache;

sf::Texture& Resource::get(const std::string& filename)
{
    // Om texturen redan finns i cachen, returnera den
    auto it = texture_cache.find(filename);

    if (it != texture_cache.end())
        return it->second;

    // Annars ladda och lägg till
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        throw std::runtime_error("Texture loading failed");
    }

    // Insert returnerar pair<iterator, bool>
    auto result = texture_cache.emplace(filename, std::move(texture));
    return result.first->second;
}

void Resource::clear()
{
    texture_cache.clear();
}
