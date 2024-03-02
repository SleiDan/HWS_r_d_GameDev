#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(const sf::Vector2f& position);

    void move(const sf::Vector2f& playerPosition);

    const sf::ConvexShape& getShape() const;

    int getHitCount() const;
    
    int getExpForKilling() const {return expForKilling;}

    void incrementHitCount();

    bool operator==(const Enemy& other) const;

    int getDamage(){return damage;}

private:
    sf::ConvexShape shape;
    float speed;
    int hitCount = 0;
    int damage = 10;
    int expForKilling = 20;
};
