﻿#include "Game.h"
#include <algorithm>
#include <iostream>
#include <random>

constexpr float M_PI = 3.14159265358979323846f;

constexpr float xField = 3000.f;

constexpr float yField = 2000.f;

std::mt19937 rng(std::random_device{}());

float randomInRange(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
}

float randomAngle() {
    std::uniform_real_distribution<float> dist(0.f, 2 * M_PI);
    return dist(rng);
}


// Constructor for the Game class
Game::Game()
    : window(sf::VideoMode::getFullscreenModes()[0], "SFML Shooting", sf::Style::Fullscreen),
      player(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f)),
      fieldSize(sf::Vector2f(xField, yField)) {
    window.setFramerateLimit(60); // Set the framerate limit for smooth animation
    createBackground(); // Create the background grid
   

    // Load font
    if (!font.loadFromFile("arial.ttf")) {
        // Handle font loading error
    }
    
    // Configure paused text
    pausedText.setFont(font);
    pausedText.setString("PAUSED");
    pausedText.setCharacterSize(50);
    pausedText.setFillColor(sf::Color::White);
    pausedText.setStyle(sf::Text::Bold);
    pausedText.setOrigin(pausedText.getLocalBounds().width / 2.f, pausedText.getLocalBounds().height / 2.f);
    pausedText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    gameOverText.setFont(font);
    gameOverText.setString("GameOver! Press R to restart");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setOrigin(pausedText.getLocalBounds().width / 2.f, pausedText.getLocalBounds().height / 2.f);
    gameOverText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

// Main game loop
void Game::run() {
    GameState gameState = GameState::Running;
    while (window.isOpen()) {
        update(); // Update game logic
        renderGameObjects(); // Render the game state
    }
}

// Function to create the background grid
void Game::createBackground() {
    sf::Color color1(200, 200, 200); // Define color1
    sf::Color color2(220, 220, 220); // Define color2
    bool isColor1 = true; // Flag to alternate between colors
    float size = 50.f; // Size of each grid cell
    for (float y = 0; y < fieldSize.y; y += size) {
        isColor1 = !isColor1;
        for (float x = 0; x < fieldSize.x; x += size) {
            sf::RectangleShape cell(sf::Vector2f(size, size)); // Create a rectangle representing a cell
            cell.setPosition(x, y); // Set position of the cell
            cell.setFillColor(isColor1 ? color1 : color2); // Alternate cell colors
            background.emplace_back(cell); // Add cell to background vector
            isColor1 = !isColor1; // Toggle color for next cell
        }
    }
}


void Game::handleUserInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close(); // Close the window if the close event is triggered
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window.close(); // Close the window if the Escape key is pressed
            else if (event.key.code == sf::Keyboard::P)
                gameState = (gameState == GameState::Paused) ? GameState::Running : GameState::Paused;
            break;
        default:
            break;
        }
    }
}

void Game::renderPausedText() {
    window.draw(pausedText);
}

void Game::handlePlayerDeadInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close(); // Закрытие окна при нажатии на крестик
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window.close(); // Закрытие окна при нажатии на Escape
            else if (event.key.code == sf::Keyboard::R)
                restartGame(); // Перезапуск игры при нажатии на R
            break;
        default:
            break;
        }
    }
}

void Game::restartGame() {
    // Сброс состояния игрока
    player.setHP(100); // предполагается, что у вас есть метод setHP и переменная initialHP
    player.getShape().setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Возвращает игрока в начальную позицию

    // Очистка списков врагов и пуль
    enemies.clear();
    bullets.clear();

    // Сброс таймеров
    timeSinceLastShot = sf::Time::Zero;
    timeSinceLastSpawn = sf::Time::Zero;

    // Возможно, вам понадобится сбросить другие аспекты игры, такие как счетчик очков или уровень

    // Возвращение в игровой режим
    gameState = GameState::Running;

    // Сброс камеры/вида, если необходимо
    sf::Vector2f viewCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
    view.setCenter(viewCenter);

}

void Game::renderGameOverMessage() {
    window.draw(gameOverText);
}

void Game::updateGameLogic() {
    // Handle player movement
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        movement.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += 1.f;


    // Move and rotate the player
    player.move(normalize(movement));
    player.rotate(window, sf::Mouse::getPosition(window));
    
    // Keep the player within the game field bounds
    sf::Vector2f playerPos = player.getShape().getPosition();
    sf::Vector2f viewSize = window.getView().getSize();
    float halfViewWidth = viewSize.x / 2.f;
    float halfViewHeight = viewSize.y / 2.f;
    sf::Vector2f viewCenter = view.getCenter();
    viewCenter.x = std::max(halfViewWidth, std::min(playerPos.x, fieldSize.x - halfViewWidth));
    viewCenter.y = std::max(halfViewHeight, std::min(playerPos.y, fieldSize.y - halfViewHeight));
    view.setCenter(viewCenter);
    
    // Adjust the view size
    sf::Vector2u windowSize = window.getSize();
    view.setSize(viewSize.x, viewSize.x * (static_cast<float>(windowSize.y) / windowSize.x));

    
    
    // Move enemies towards the player
    for (auto& enemy : enemies) {
        enemy.move(player.getShape().getPosition());
    }

    // Check for bullet-enemy collisions
    for (auto bulletIt = bullets.begin(); bulletIt != bullets.end(); ) {
        bool bulletHitEnemy = false; // Flag to track whether the bullet hit an enemy
        for (auto& enemy : enemies) {
            if (bulletIt->intersects(enemy.getShape())) {
                // Increment the hit count on the enemy
                enemy.incrementHitCount();
                bulletHitEnemy = true; // Set the flag to indicate bullet hit an enemy
                break; // Exit the loop as the bullet has hit an enemy
            }
        }

        // If the bullet did not hit an enemy, move to the next bullet
        if (!bulletHitEnemy) {
            ++bulletIt;
        } else {
            bulletIt = bullets.erase(bulletIt); // Remove the bullet as it hit an enemy
        }
    }

    for (auto enemy : enemies)
    {
        if (player.getShape().getGlobalBounds().intersects(enemy.getShape().getGlobalBounds())) {
            timeSinceLastHit += hittingClock.restart();
            if(timeSinceLastHit >= hitInterval)
            {
                player.setHP(enemy.getDamage());
                timeSinceLastHit = sf::Time::Zero;
            }
            std::cout << player.getHP() << std::endl; 
            if(player.getHP() <= 0)
            {
                gameState = GameState::PlayerDead;
            }
        }
    }

    // Remove enemies whose hit count has reached two
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& enemy) {
        return enemy.getHitCount() >= 2;
    }), enemies.end());

    // Handle shooting and spawning
    timeSinceLastShot += shootingClock.restart();

    //Bullets
    if (timeSinceLastShot >= shootInterval) {
        bullets.emplace_back(player.getShape().getPosition(), player.getShape().getRotation());
        timeSinceLastShot = sf::Time::Zero;
    }

    timeSinceLastSpawn += spawningClock.restart();

    //Enemies
    if (timeSinceLastSpawn >= spawnEnemyInterval) {
        float radius = randomInRange(700.f, 1000.f); // Радиус "бублика"
        float angle = randomAngle(); // Случайный угол в радианах
        float offsetX = radius * std::cos(angle);
        float offsetY = radius * std::sin(angle);

        sf::Vector2f enemyPosition = player.getShape().getPosition() + sf::Vector2f(offsetX, offsetY);
        enemies.emplace_back(enemyPosition);
        timeSinceLastSpawn = sf::Time::Zero;
    }

    // Move bullets
    for (auto& bullet : bullets) {
        bullet.move();
    }
}

// Function to update game logic
void Game::update() {

    switch (gameState) {
    case GameState::Running:
        handleUserInput();
        updateGameLogic();
        renderGameObjects();

        break;
    case GameState::Paused:
        handleUserInput();
        renderGameObjects();
        renderPausedText();

        break;
    case GameState::PlayerDead:
        handlePlayerDeadInput();
        renderGameOverMessage();

        break;

    }
    
}

// Function to render the game state
void Game::renderGameObjects() {
    window.clear(); // Clear the window

    // Draw background cells
    for (const auto& cell : background) {
        window.draw(cell);
    }

    // Draw player, enemies, and bullets
    window.draw(player.getShape());
    for (const auto& enemy : enemies) {
        window.draw(enemy.getShape());
    }
    for (const auto& bullet : bullets) {
        window.draw(bullet.getShape());
    }

    if (gameState == GameState::Paused) {
        window.draw(pausedText);
    }

    window.setView(view); // Set view to focus on player
    window.display(); // Display the rendered frame
}

// Function to normalize a vector
sf::Vector2f Game::normalize(const sf::Vector2f& vector) {
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y); // Calculate vector length
    return (length != 0.f) ? sf::Vector2f(vector.x / length, vector.y / length) : vector; // Normalize the vector if not zero
}
