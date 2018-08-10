#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "BattleBoss1.h"
#include "BattleDefend.h"


int main()
{

    std::srand ( unsigned ( std::time(0) ) );
    BattleBase* baseRight = new BattleBoss1();
    BattleBase* baseLeft = new BattleDefend();

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::Clock clock;
    clock.restart();
    sf::Time prevTime = clock.getElapsedTime();
    sf::Time currTime = clock.getElapsedTime();
    sf::VertexArray line;
    line.setPrimitiveType(sf::PrimitiveType::Lines);
    line.append(sf::Vertex(sf::Vector2f(window.getSize().x/2, 0), sf::Color::Green));
    line.append(sf::Vertex(sf::Vector2f(window.getSize().x/2, window.getSize().y), sf::Color::Green));




    while (window.isOpen())
    {
        prevTime = currTime;
        currTime = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            baseRight -> onEvent(event);
            baseLeft -> onEvent(event);
        }

        baseRight -> update(currTime-prevTime);
        baseLeft -> update(currTime-prevTime);
        window.clear();
        window.draw(line);
        baseRight -> draw(window);
        baseLeft -> draw(window);
        window.display();


    }

    delete baseRight;
    delete baseLeft;

    return 0;
}
