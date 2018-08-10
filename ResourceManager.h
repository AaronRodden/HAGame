#ifndef __HAGame__ResourceManager__
#define __HAGame__ResourceManager__

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

struct TextureManager {
    std::map<std::string, sf::Texture> textures;
};

struct SoundFXManager {
    std::map<std::string, sf::SoundBuffer> sounds;
};

class ResourceManager {
    static TextureManager tm;
    static SoundFXManager sm;
public:
    static sf::Texture& getTexture(std::string path) {
        auto t=tm.textures.find(path);
        if(t==tm.textures.end()) {
            tm.textures[path]=sf::Texture();
            tm.textures[path].loadFromFile(path);
            return getTexture(path);
        }
        else {
            return t->second;
        }
    }


    static sf::SoundBuffer& getSoundFX(std::string path) {
        auto s=sm.sounds.find(path);
        if(s==sm.sounds.end()) {
            sm.sounds[path]=sf::SoundBuffer();
            sm.sounds[path].loadFromFile(path);
            return getSoundFX(path);
        }
        else {
            return s->second;
        }
    }
};

#endif // __HAGame__ResourceManager__
