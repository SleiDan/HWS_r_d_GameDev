#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Player {
public:
    Player(const sf::Vector2f& position);

    void move(const sf::Vector2f& movement);

    void rotate(const sf::RenderWindow& window, const sf::Vector2i& targetPosition);
    void updateAnimation();
    sf::Sprite& getSprite();
    void playSoundShot();

    void addExp(int additionalExp) {exp += additionalExp;}
    void setExp(int newExp) {exp = newExp;}

    float getExp() {return exp;}

    int getHP() {return HP;}
    void setHP(int newHP) { HP = newHP;}
    void Damage(int damage);

    float getExpForNewLvl() {return expForNewLvl;}
    void setExpForNewLvl(float newExpForNewLvl) {expForNewLvl = newExpForNewLvl;}

    float getAttackSpeed() {return attackSpeed;}
    void setAttackSpeed(float newAttakcSpeed) {attackSpeed -= newAttakcSpeed;}
    void rotate(sf::Vector2f window);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float attackSpeed = 1;
    float expForNewLvl = 100.f;
    float exp = 0.f;
    int HP = 100;
    float speed;
    int currentFrame;
    sf::Clock animationTimer;
    sf::Time frameDuration = sf::Time::Zero;
    sf::SoundBuffer ShotBuffer;
    sf::Sound sound;

};
