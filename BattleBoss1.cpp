#include "BattleBoss1.h"
#include <cmath>

BattleBoss1::BattleBoss1() {

    arrow = sf::Sprite(arrowTexture);
    arrow.setOrigin(arrowTexture.getSize().x/2, arrowTexture.getSize().y/2);
    arrow.setPosition(arrowTexture.getSize().x/2, arrowTexture.getSize().y/2);

    boss = sf::Sprite(bossTexture);
    boss.setScale(0.5,0.5);
    boss.setOrigin(bossTexture.getSize().x/2, bossTexture.getSize().y/2);
    boss.setPosition(bossTexture.getSize().x/2, bossTexture.getSize().y/2);

    hurt = sf::Sound(hurtBuffer);
    arrowSound = sf::Sound(arrowBuffer);

    bossTrack.openFromFile("Resources/VampireKiller.ogg");
    bossTrack.setLoop(true);
    bossTrack.play();

    Arrow up=Arrow(UP), down=Arrow(DOWN), left=Arrow(LEFT), right=Arrow(RIGHT);

    attackPatterns.push_back({Arrow(UP),Arrow(UP),Arrow(UP)});
    attackPatterns.push_back({Arrow(DOWN),Arrow(UP),Arrow(LEFT)});
    attackPatterns.push_back({Arrow(DOWN),Arrow(DOWN)});
    attackPatterns.push_back({Arrow(UP),Arrow(RIGHT),Arrow(DOWN),Arrow(RIGHT)});
    attackPatterns.push_back({Arrow(UP),Arrow(DOWN),Arrow(UP)});
    attackPatterns.push_back({Arrow(LEFT),Arrow(DOWN),Arrow(RIGHT)});
    attackPatterns.push_back({Arrow(UP),Arrow(DOWN)});
    attackPatterns.push_back({Arrow(RIGHT),Arrow(RIGHT),Arrow(DOWN),Arrow(RIGHT)});
    attackPatterns.push_back({Arrow(UP),Arrow(UP),Arrow(DOWN),Arrow(DOWN),Arrow(LEFT),Arrow(RIGHT),Arrow(LEFT),Arrow(RIGHT)});
    attackPatterns.push_back({up,down,up,down,up});
    attackPatterns.push_back({right,down,down,right,left});
    attackPatterns.push_back({up,left,down,right});
    attackPatterns.push_back({up,left,down,right});
    attackPatterns.push_back({right,down,right});
    attackPatterns.push_back({down,left,up});
    attackPatterns.push_back({right,right,right,up,up,up});
    attackPatterns.push_back({up,left,up,down,right,down});


    std::random_shuffle(attackPatterns.begin(),attackPatterns.end());
}

void BattleBoss1::onEvent(sf::Event& event) {


            if (event.type == sf::Event::KeyPressed && event.key.code == attackPatterns[indexPattern][indexAttack].getKey()
                && shake == sf::Time::Zero) {
                indexAttack++;
                arrowSound.play();
                std::cout << "building attack up" << std::endl;

                if (indexAttack >= attackPatterns[indexPattern].size()) {
                    //completed attack
                    std::cout << "ATTACK!!" << std::endl;
                    hurt.play();
                    shakeBoss = sf::seconds(0.5);
                    indexAttack = 0;
                    indexPattern++;

                    if (indexPattern >= attackPatterns.size()) {
                        std::cout << "all out of attacks" << std::endl;
                        indexPattern = 0;
                        std::random_shuffle(attackPatterns.begin(),attackPatterns.end());
                    }
                }
            }

            else if (event.type == sf::Event::KeyPressed && event.key.code != attackPatterns[indexPattern][indexAttack].getKey()
                     && shake == sf::Time::Zero){
                if (event.key.code == sf::Keyboard::Left||event.key.code == sf::Keyboard::Right||event.key.code == sf::Keyboard::Up
                    ||event.key.code == sf::Keyboard::Down) {
                    std::cout << "You Pressed the wrong button!!" << std::endl;
                    shake = sf::seconds(0.5);
                }

            }
}

void BattleBoss1::update(sf::Time delta){

shake-=delta;
shakeBoss-=delta;

if (delta >= shake) {
    shake = sf::Time::Zero;
}

if(delta >= shakeBoss) {
    shakeBoss = sf::Time::Zero;
}

}
void BattleBoss1::draw(sf::RenderTarget& window){

    boss.setPosition(window.getSize().x/4, window.getSize().y/2 - 220);

    if (shakeBoss > sf::Time::Zero) {
        boss.move(-10*cosf(shakeBoss.asSeconds()*30), 0);
    }
    window.draw(boss);

    for (int i = indexAttack; i < attackPatterns[indexPattern].size(); i++) {

        Arrow& temp = attackPatterns[indexPattern][i];
        arrow.setRotation(temp.getAngle());
        arrow.setPosition(window.getSize().x/2 + 300, 50+i*arrowTexture.getSize().y);


        if (shake > sf::Time::Zero && i == indexAttack) {
            arrow.move(-10*cosf(shake.asSeconds()*30), 0);
        }
        window.draw(arrow);

    }



}
BattleBoss1::~BattleBoss1(){

}
