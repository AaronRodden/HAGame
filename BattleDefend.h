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
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "BattleBase.h"
#include "ResourceManager.h"


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

    sf::SoundBuffer& shieldBreakBuffer = ResourceManager::getSoundFX("shieldbreak.wav");
    sf::Sound shieldSound;

public:
    BattleDefend();
    virtual void onEvent(sf::Event& event) override;
    virtual void update(sf::Time delta) override;
    virtual void draw(sf::RenderTarget& window) override;
    virtual ~BattleDefend();
};

#endif /* defined(_HAGame__BattleDefend_) */
