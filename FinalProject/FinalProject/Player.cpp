#include "Player.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Player::Player(const sf::Vector2f& position)
    : shape(sf::Vector2f(50.f, 50.f)), speed(3.f) {
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(25.f, 25.f);
    shape.setPosition(position);
}

void Player::move(const sf::Vector2f& movement) {
    shape.move(speed * movement);
}

void Player::rotate(const sf::RenderWindow& window, const sf::Vector2i& targetPosition) {
    sf::Vector2f worldMousePos = window.mapPixelToCoords(targetPosition);
    sf::Vector2f playerCenter = shape.getPosition();
    float dx = worldMousePos.x - playerCenter.x;
    float dy = worldMousePos.y - playerCenter.y;
    float angle = std::atan2(dy, dx) * 180 / M_PI;
    shape.setRotation(angle);
}

sf::RectangleShape Player::getShape() const {
    return shape;
}

