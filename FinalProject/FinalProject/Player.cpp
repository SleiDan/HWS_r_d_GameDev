#include "Player.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Player::Player(const sf::Vector2f& position)
    : speed(3.f) {
    if (!texture.loadFromFile("Player/player.png")) { // Замените "player.png" на путь к вашему файлу изображения
        std::cerr << "Could not load player texture" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f); // Центрирование спрайта относительно его текстуры
    sprite.setPosition(position);
}

void Player::move(const sf::Vector2f& movement) {
    sprite.move(speed * movement);
}

void Player::rotate(const sf::RenderWindow& window, const sf::Vector2i& targetPosition) {
    sf::Vector2f worldMousePos = window.mapPixelToCoords(targetPosition);
    sf::Vector2f playerCenter = sprite.getPosition();
    float dx = worldMousePos.x - playerCenter.x;
    float dy = worldMousePos.y - playerCenter.y;
    float angle = std::atan2(dy, dx) * 180 / M_PI;
    sprite.setRotation(angle);
}

sf::Sprite& Player::getSprite() {
    return sprite;
}

