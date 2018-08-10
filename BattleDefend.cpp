//
//  BattleDefend.cpp
//  HAGame
//
//  Created by Christopher Hitchcock on 8/9/18.
//  Copyright � 2018 Christopher Hitchcock. All rights reserved.
//

#include "BattleDefend.h"

std::vector<sf::Keyboard::Key> BattleDefend::keys={sf::Keyboard::Q, sf::Keyboard::W, sf::Keyboard::E, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::Y, sf::Keyboard::U, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::P};
std::vector<sf::Color> BattleDefend::colors={sf::Color::Red, sf::Color::Cyan, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue, sf::Color::Magenta, sf::Color::White};


BattleDefend::BattleDefend() {
    shieldStates.resize(10);
    circ.setFillColor(sf::Color::White);
    circ.setRadius(10.f);
    circ.setOrigin(circ.getRadius(), circ.getRadius());

    rect.setSize(sf::Vector2f(64, 16));

    shieldSound = sf::Sound(shieldBreakBuffer);

}
void BattleDefend::onEvent(sf::Event& event) {
    for(int i=0;i<4;i++) {
        if(event.type==sf::Event::KeyPressed&&event.key.code==keys[i]) {
            if(shieldStates[i].alpha!=0) {
                shieldStates[i].alpha+=0.25;
            }
        }
    }
}
void BattleDefend::update(sf::Time delta) {
    for(int i=0;i<4;i++) {
        if(sf::Keyboard::isKeyPressed(keys[i])) {
            shieldStates[i].alpha+=delta.asSeconds();
            if(shieldStates[i].alpha>=3.f&&!shieldStates[i].broken) {
                shieldSound.play();
                shieldStates[i].broken=true;
            }
        }
        else {
            shieldStates[i].alpha-=delta.asSeconds();
        }
        if(shieldStates[i].alpha>=3.f) {
            shieldStates[i].alpha=3.f;
        }
        if(shieldStates[i].alpha<=0) {
            shieldStates[i].alpha=0;
            shieldStates[i].broken=false;
        }
    }
}
void BattleDefend::draw(sf::RenderTarget& window) {


    window.draw(circ);
    for(int i=0;i<4;i++) {
        if(sf::Keyboard::isKeyPressed(keys[i])) {
            sf::Color c=colors[i];
            c.a=std::max((3.f-shieldStates[i].alpha)/3.f, 0.f)*255.f;
            rect.setFillColor(c);
            rect.setPosition((window.getSize().x/4-(rect.getSize().x*3.5))+i*rect.getSize().x*2, window.getSize().y/2 + 220);
            window.draw(rect);
        }
    }

}
BattleDefend::~BattleDefend() {

}
