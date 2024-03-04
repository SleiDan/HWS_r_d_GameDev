#include "Player.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <SFML/System.hpp>
#include <SFML/Audio/Sound.hpp>

constexpr float M_PI = 3.14159265358979323846f;

Player::Player(const sf::Vector2f& position)
    : speed(3.f), currentFrame(0), frameDuration(sf::seconds(0.2f)) { 
    if (!texture.loadFromFile("Player/player1.png")) {
        std::cerr << "Could not load player texture" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setPosition(position);
}

void Player::move(const sf::Vector2f& movement) {
    sprite.move(speed * movement);
}

void Player::rotate(sf::Vector2f targetPosition) {
    sf::Vector2f currentPosition = this->getSprite().getPosition();
    float dx = targetPosition.x - currentPosition.x;
    float dy = targetPosition.y - currentPosition.y;
    float angle = std::atan2(dy, dx) * 180 / M_PI;
    this->getSprite().setRotation(angle);
}
void Player::updateAnimation() {
    if (animationTimer.getElapsedTime() >= frameDuration) { // Check if it's time to update the frame
        
        currentFrame++; // Move to the next frame
        if (currentFrame > 3) { // If it's the last frame, loop back to the first frame
            currentFrame = 0; 
        }

        // Generate the filename for the next frame's texture
        std::string textureName = "Player/player" + std::to_string(currentFrame + 1) + ".png";

        if (!texture.loadFromFile(textureName)) { // Load the texture for the next frame
            std::cerr << "Could not load player texture " << textureName << std::endl; // Handle texture loading failure
        }

        // Set the sprite's texture to the newly loaded texture
        sprite.setTexture(texture);

        animationTimer.restart(); // Restart the animation timer for the next frame
    }
}
 

sf::Sprite& Player::getSprite() {
    return sprite;
}

void Player::playSoundShot()
{
    std::srand(std::time(nullptr));

    int soundNumber = std::rand() % 2 + 1;

    std::string fileName = "Sounds/shot" + std::to_string(soundNumber) + ".mp3";

    if (!ShotBuffer.loadFromFile(fileName)) {
        std::cerr << "Failed to load sound file: " << fileName << std::endl;
        return;
    }

    sound.setBuffer(ShotBuffer);

    sound.play();
}
