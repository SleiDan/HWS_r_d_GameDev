#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Vector2f& position);

    void move(const sf::Vector2f& movement);

    void rotate(const sf::RenderWindow& window, const sf::Vector2i& targetPosition);

    sf::RectangleShape getShape() const;

    int getHP() {return HP;}
    void setHP(int damage) { HP -= damage;}

private:
    sf::RectangleShape shape;
    int HP = 100;
    float speed;
};
