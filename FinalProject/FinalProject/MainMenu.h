#pragma once

#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu(float screenWidth, float screenHeight);

    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    bool getGameStarted() const { return gameStarted; }

private:
    sf::Text startButton;
    sf::Font font;
    bool gameStarted = false;
};