#ifndef __HAGame__BattleBase__
#define __HAGame__BattleBase__

#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class BattleBase {

public:
    BattleBase() { }
    virtual void onEvent(sf::Event& event) { }
    virtual void update(sf::Time delta) { }
    virtual void draw(sf::RenderTarget& window) { }
    virtual ~BattleBase() { }
};

#endif //__HAGame__BattleBase__
