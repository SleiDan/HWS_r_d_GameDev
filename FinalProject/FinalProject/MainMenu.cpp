#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(float screenWidth, float screenHeight) : gameStarted(false) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Could not load font" << std::endl;
    }

    startButton.setFont(font);
    startButton.setString("Start");
    startButton.setCharacterSize(50);
    startButton.setFillColor(sf::Color::White);
    startButton.setOrigin(startButton.getLocalBounds().width / 2.f, startButton.getLocalBounds().height / 2.f);
    startButton.setPosition(screenWidth / 2.f, screenHeight / 2.f);
}

void MainMenu::handleInput(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (startButton.getGlobalBounds().contains(mousePosition)) {
                gameStarted = true;
            }
        }
    }
}

void MainMenu::draw(sf::RenderWindow& window) {
    window.draw(startButton);
}
