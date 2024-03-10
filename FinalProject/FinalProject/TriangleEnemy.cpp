#include "TriangleEnemy.h"
#include <cmath>

TriangleEnemy::TriangleEnemy(const sf::Vector2f& position) {
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(0.f, 0.f));
    shape.setPoint(1, sf::Vector2f(50.f, 0.f));
    shape.setPoint(2, sf::Vector2f(25.f, 50.f));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(25.f, 25.f);
    shape.setPosition(position);
    expForKilling = 20;
    damage = 10;
}

void TriangleEnemy::move(const sf::Vector2f& playerPosition) {
    sf::Vector2f direction = playerPosition - shape.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.f) {
        direction /= length; // Normalize the direction vector
    }
    float speed = 3.f; // Speed can be adjusted as needed
    shape.move(direction * speed); // Move the enemy towards the player
}

const sf::Shape& TriangleEnemy::getShape() const {
    return shape;
}

void TriangleEnemy::update(const sf::Vector2f& playerPosition, float deltaTime) {
    move(playerPosition); // Call the move function to update position
}
