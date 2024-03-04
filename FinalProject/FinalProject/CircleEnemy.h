#pragma once

#include "Enemy.h"
#include "Game.h"

class CircleEnemy : public Enemy {
public:
    CircleEnemy(const sf::Vector2f& position, Game* game);
    void move(const sf::Vector2f& playerPosition);
    const sf::Shape& getShape() const override;
    void update(const sf::Vector2f& playerPosition, float deltaTime) override;
    void shoot(const sf::Vector2f& playerPosition);

private:
    sf::CircleShape shape;
    float shootTimer;
    float shootInterval;
    Game* game; 
};
