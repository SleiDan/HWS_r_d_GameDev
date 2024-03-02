#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Vector2f& position);

    void move(const sf::Vector2f& movement);

    void rotate(const sf::RenderWindow& window, const sf::Vector2i& targetPosition);

    sf::RectangleShape getShape() const;

    void addExp(int additionalExp) {exp += additionalExp;}
    void setExp(int newExp) {exp = newExp;}

    int getExp() {return exp;}

    int getHP() {return HP;}
    void setHP(int damage) { HP -= damage;}

    int getExpForNewLvl() {return expForNewLvl;}
    void setExpForNewLvl(int newExpForNewLvl) {expForNewLvl = newExpForNewLvl;}

private:
    sf::RectangleShape shape;
    int expForNewLvl = 100;
    int exp = 0;
    int HP = 100;
    float speed;
};
