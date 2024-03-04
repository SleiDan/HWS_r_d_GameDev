#pragma once

#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu(float screenWidth, float screenHeight);
    void createBackground(float screenWidth, float screenHeight, sf::RenderWindow& window);

    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    bool getGameStarted() const { return gameStarted; }

private:
    sf::Text startButton;
    sf::Font font;
    sf::Text exitButton;
    sf::RectangleShape exitButtonBackground;

    sf::RectangleShape startButtonBackground;
    bool gameStarted;
};