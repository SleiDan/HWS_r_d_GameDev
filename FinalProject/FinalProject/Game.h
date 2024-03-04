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
    sf::Clock deltaClock;
    sf::Clock shootingClock;
    sf::Clock spawningClock;
    sf::Clock hittingClock;
    sf::Time timeSinceLastShot = sf::Time::Zero;
    sf::Time shootInterval;
    std::vector<sf::RectangleShape> background;
    sf::Vector2f fieldSize;
    sf::View view;
    sf::Time timeSinceLastSpawn = sf::Time::Zero;
    const sf::Time spawnEnemyInterval = sf::seconds(1.f);
    GameState gameState = GameState::Running;
    sf::Font font;
    sf::Text pausedText;
    sf::Text gameOverText;
    sf::Text hpText;
    sf::Text expText;

    sf::Time timeSinceLastHit = sf::Time::Zero;
    const sf::Time hitInterval = sf::seconds(1.f);
    float progress = 0.0f;
    sf::RectangleShape progressHpBar;
    sf::RectangleShape progressExpBar;
    sf::RectangleShape progressHpBarBlack;
    sf::RectangleShape progressExpBarBlack;
    sf::View uiView = window.getDefaultView();

    void createBackground();
    void handleUserInput();
    void renderPausedText();
    void handlePlayerDeadInput();
    void restartGame();
    void renderGameOverMessage();
    void updateGameLogic(float deltaSeconds);
    void update(float deltaSeconds);
    void renderGameObjects();
    sf::Vector2f normalize(const sf::Vector2f& vector);
    void updateHpProgressBar();
    void initializeHpProgressBar();
    void updateExpProgressBar();
    void initializeExpProgressBar();
    void updateExpProgressBarBlack();

    
};
