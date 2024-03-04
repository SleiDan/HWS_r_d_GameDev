#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Vector2f& position);

    void move(const sf::Vector2f& movement);

    void rotate(const sf::RenderWindow& window, const sf::Vector2i& targetPosition);
    sf::Sprite& getSprite();
    
    void addExp(int additionalExp) {exp += additionalExp;}
    void setExp(int newExp) {exp = newExp;}

    int getExp() {return exp;}

    int getHP() {return HP;}
    void setHP(int damage) { HP -= damage;}

    int getExpForNewLvl() {return expForNewLvl;}
    void setExpForNewLvl(int newExpForNewLvl) {expForNewLvl = newExpForNewLvl;}

    float getAttackSpeed() {return attackSpeed;}
    void setAttackSpeed(float newAttakcSpeed) {attackSpeed -= newAttakcSpeed;}

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float attackSpeed = 1;
    int expForNewLvl = 100;
    int exp = 0;
    int HP = 100;
    float speed;
};
