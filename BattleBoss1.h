#ifndef __HAGame__BattleBoss1__
#define __HAGame__BattleBoss1__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "BattleBase.h"
#include "ResourceManager.h"

class ArrowKey {
    sf::Keyboard::Key key;
    float angle;
public:
    ArrowKey(sf::Keyboard::Key key, float angle):key(key), angle(angle) {

    }
    sf::Keyboard::Key getKey() {return key;}
    float getAngle() { return angle; }
};

enum directions {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Arrow:public ArrowKey {
    static sf::Keyboard::Key getKeyFromDir(directions dir) {
        switch(dir) {
            case UP:
                return sf::Keyboard::Up;
            case DOWN:
                return sf::Keyboard::Down;
            case LEFT:
                return sf::Keyboard::Left;
            case RIGHT:
                return sf::Keyboard::Right;
        }
    }
public:
    Arrow(directions dir):ArrowKey(getKeyFromDir(dir), 90.f*dir) {

    }
};



class BattleBoss1: public BattleBase {

    sf::Texture& arrowTexture = ResourceManager::getTexture("arrow64.png");
    sf::Sprite arrow;

    sf::Texture& bossTexture = ResourceManager::getTexture("boss1.png");
    sf::Sprite boss;

    sf::SoundBuffer& hurtBuffer = ResourceManager::getSoundFX("oof.wav");
    sf::Sound hurt;

    sf::Music bossTrack;

    sf::Time shake = sf::Time::Zero;
    sf::Time shakeBoss = sf::Time::Zero;


    std::vector<std::vector<Arrow>> attackPatterns;

    int indexPattern = 0;
    int indexAttack = 0;

    typedef std::vector<Arrow> ArrowList;



public:
    BattleBoss1();
    virtual void onEvent(sf::Event& event) override;
    virtual void update(sf::Time delta) override;
    virtual void draw(sf::RenderTarget& window) override;
    virtual ~BattleBoss1();

};

#endif // __HAGame__BattleBoss1__
