#pragma once

#include "Enemy.h"

class TriangleEnemy : public Enemy {
public:
    TriangleEnemy(const sf::Vector2f& position);
    void move(const sf::Vector2f& playerPosition) override;
    const sf::Shape& getShape() const override;
    void update(const sf::Vector2f& playerPosition, float deltaTime) override;

private:
    sf::ConvexShape shape;
};