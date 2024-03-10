#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy();
    virtual void move(const sf::Vector2f& playerPosition) = 0;
    virtual const sf::Shape& getShape() const = 0;
    virtual void update(const sf::Vector2f& playerPosition, float deltaTime) = 0;
    virtual int getHitCount() const;
    virtual void incrementHitCount();
    virtual bool operator==(const Enemy& other) const;
    virtual int getExpForKilling() const;
    virtual int getDamage() const;
    virtual ~Enemy() {}

protected:
    int hitCount;
    int expForKilling;
    int damage;
};