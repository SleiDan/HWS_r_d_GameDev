#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Bullet {
public:
    Bullet(const sf::Vector2f& position, float rotation);

    void move();

    const sf::RectangleShape& getShape() const;

    bool intersects(const sf::ConvexShape& enemyShape) const;

    void playSoundShot();
    

private:
    sf::RectangleShape shape;
    float speed;
};
