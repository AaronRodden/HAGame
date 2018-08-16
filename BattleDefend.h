//
//  BattleDefend.h
//  HAGame
//
//  Created by Christopher Hitchcock on 8/9/18.
//  Copyright © 2018 Christopher Hitchcock. All rights reserved.
//

#ifndef _HAGame__BattleDefend_
#define _HAGame__BattleDefend_

#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "BattleBase.h"
#include "ResourceManager.h"

class bossAttack {
    sf::CircleShape circ;
    float yPos;
    int lane;
    std::string color;
public:
    bossAttack(float yPos, int lane, std::string color):yPos(yPos), lane(lane), color(color) {
        std::transform(color.begin(), color.end(), color.begin(), ::tolower);
        setColor(color);
    }
    void setColor(std::string color) {
        if (color == "red"){
            circ.setFillColor(sf::Color::Red);
        }
        else if (color == "cyan"){
            circ.setFillColor(sf::Color::Cyan);
        }
        else if (color == "green"){
            circ.setFillColor(sf::Color::Green);
        }
        else if (color == "yellow"){
            circ.setFillColor(sf::Color::Yellow);
        }
    }
};


class BattleDefend:public BattleBase {
    static std::vector<sf::Keyboard::Key> keys;
    static std::vector<sf::Color> colors;
    struct shieldState {
        float alpha=0;
        bool broken=false;
    };
    std::vector<shieldState> shieldStates;
    sf::CircleShape circ;
    sf::RectangleShape rect;
    sf::CircleShape shield;

    sf::SoundBuffer& shieldBreakBuffer = ResourceManager::getSoundFX("Resources/shieldbreak.wav");
    sf::Sound shieldSound;

    sf::Font font;
    sf::Text Q;
    sf::Text W;
    sf::Text E;
    sf::Text R;
    std::vector<sf::Text> qwer;



public:
    BattleDefend();
    virtual void onEvent(sf::Event& event) override;
    virtual void update(sf::Time delta) override;
    virtual void draw(sf::RenderTarget& window) override;
    virtual ~BattleDefend();
};

#endif /* defined(_HAGame__BattleDefend_) */
