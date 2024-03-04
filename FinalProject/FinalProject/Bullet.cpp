﻿#include "Bullet.h"
#include <cmath>
#include <iostream>

constexpr float M_PI = 3.14159265358979323846f;


Bullet::Bullet(const sf::Vector2f& position, float rotation)
    : shape(sf::Vector2f(10.f, 10.f)), speed(5.f) {
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(position);
    shape.setRotation(rotation);
}

void Bullet::move() {
    float bulletAngle = shape.getRotation() * M_PI / 180;
    shape.move(speed * std::cos(bulletAngle), speed * std::sin(bulletAngle));
}

const sf::RectangleShape& Bullet::getShape() const {
    return shape;
}

bool Bullet::intersects(const sf::FloatRect& bounds) const {
    return shape.getGlobalBounds().intersects(bounds);
}

