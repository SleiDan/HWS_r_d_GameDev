#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>

enum class GameState {
    Running,
    Paused,
    PlayerDead
};


class Game {
public:
    Game();

    void run();

private:
    sf::RenderWindow window;
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    sf::Clock shootingClock;
    sf::Clock spawningClock;
    sf::Clock hittingClock;
    sf::Time timeSinceLastShot = sf::Time::Zero;
    const sf::Time shootInterval = sf::seconds(0.5f);
    std::vector<sf::RectangleShape> background;
    sf::Vector2f fieldSize;
    sf::View view;
    sf::Time timeSinceLastSpawn = sf::Time::Zero;
    const sf::Time spawnEnemyInterval = sf::seconds(1.f);
    GameState gameState = GameState::Running;
    sf::Font font;
    sf::Text pausedText;
    sf::Text gameOverText;
    sf::Time timeSinceLastHit = sf::Time::Zero;
    const sf::Time hitInterval = sf::seconds(1.f);

    void createBackground();

    void handleUserInput();
    void renderPausedText();
    void handlePlayerDeadInput();
    void restartGame();
    void renderGameOverMessage();
    void updateGameLogic();

    void update();

    void renderGameObjects();

    sf::Vector2f normalize(const sf::Vector2f& vector);
};
