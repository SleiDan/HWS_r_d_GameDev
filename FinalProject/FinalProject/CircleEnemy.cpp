#include "CircleEnemy.h"
#include <cmath>

#include "Bullet.h"

constexpr float M_PI = 3.14159265358979323846f;

CircleEnemy::CircleEnemy(const sf::Vector2f& position, Game* game) : game(game), shootTimer(2.f), shootInterval(2.f) {
    shape.setRadius(25.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(25.f, 25.f);
    shape.setPosition(position);
    expForKilling = 10; // Circle enemies give less exp
    damage = 20; // Circle enemies do more damage
}

void CircleEnemy::move(const sf::Vector2f& playerPosition) {
    sf::Vector2f direction = playerPosition - shape.getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    
    if (distance > 300.f) { // Enemy tries to keep within a certain range
        if (distance != 0.f) {
            direction /= distance; // Normalize the direction vector
        }
        float speed = 2.f; // Slower speed compared to TriangleEnemy
        shape.move(direction * speed); // Move the enemy towards the player
    }
}

const sf::Shape& CircleEnemy::getShape() const {
    return shape;
}

void CircleEnemy::update(const sf::Vector2f& playerPosition, float deltaTime) {
    move(playerPosition); // Call the move function to update position
    
    shootTimer -= deltaTime;
    if (shootTimer <= 0) {
        shoot(playerPosition);
        shootTimer = shootInterval;
    }
}

float calculateRotationTowards(const sf::Vector2f& startPosition, const sf::Vector2f& targetPosition) {
    const sf::Vector2f delta = targetPosition - startPosition;
    const float rotationRadians = std::atan2(delta.y, delta.x);
    const float rotationDegrees = rotationRadians * 180.f / M_PI;
    return rotationDegrees;
}

void CircleEnemy::shoot(const sf::Vector2f& playerPosition) {
    float rotation = calculateRotationTowards(shape.getPosition(), playerPosition);
    game->addEnemyBullet(Bullet(shape.getPosition(), rotation));
}
