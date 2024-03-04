#include "Enemy.h"
#include <cmath>

Enemy::Enemy(const sf::Vector2f& position)
    : speed(4.f) {
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(0.f, 0.f));
    shape.setPoint(1, sf::Vector2f(50.f, 0.f));
    shape.setPoint(2, sf::Vector2f(25.f, 50.f));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(25.f, 25.f);
    shape.setPosition(position);
}

void Enemy::move(const sf::Vector2f& playerPosition) {
    sf::Vector2f direction = playerPosition - shape.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.f) {
        direction /= length;
    }
    shape.move(speed * direction);
}

const sf::ConvexShape& Enemy::getShape() const {
    return shape;
}

int Enemy::getHitCount() const {
    return hitCount;
}

void Enemy::incrementHitCount() {
    hitCount++;
}

bool Enemy::operator==(const Enemy& other) const {
    return this == &other;
}
