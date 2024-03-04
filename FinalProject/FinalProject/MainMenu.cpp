#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(float screenWidth, float screenHeight) : gameStarted(false) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Could not load font" << std::endl;
    }

    startButton.setFont(font);
    startButton.setString("Start");
    startButton.setCharacterSize(100);
    startButton.setFillColor(sf::Color::Black);

    startButtonBackground.setSize(sf::Vector2f(startButton.getLocalBounds().width*2, startButton.getLocalBounds().height*2));
    startButtonBackground.setFillColor(sf::Color(255, 255, 255));
    startButtonBackground.setOrigin(startButtonBackground.getSize().x / 2.f, startButtonBackground.getSize().y / 2.f);
    startButtonBackground.setPosition(screenWidth / 2.f, screenHeight / 2.f);
    
    startButton.setOrigin(startButton.getLocalBounds().width / 2.f, startButton.getLocalBounds().height / 2.f);
    startButton.setPosition(screenWidth / 2.f - 10.f, screenHeight / 2.f - 30.f);

    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(50); // Меньший размер по сравнению с кнопкой "Start"
    exitButton.setFillColor(sf::Color::Black);

    exitButtonBackground.setSize(sf::Vector2f(exitButton.getLocalBounds().width*2.f, exitButton.getLocalBounds().height*2.f));
    exitButtonBackground.setFillColor(sf::Color(255, 255, 255)); // Серый фон для кнопки
    exitButtonBackground.setOrigin(exitButtonBackground.getSize().x / 2.f, exitButtonBackground.getSize().y / 2.f);
    exitButtonBackground.setPosition(screenWidth / 2.f, screenHeight /2.f + 120.f); // Пример позиции

    exitButton.setOrigin(exitButton.getLocalBounds().width / 2.f, exitButton.getLocalBounds().height / 2.f);
    exitButton.setPosition(screenWidth / 2.f - 10.f, screenHeight /2.f + 110.f); // Совпадает с позицией фона

}

void MainMenu::createBackground(float screenWidth, float screenHeight, sf::RenderWindow& window) {
    sf::Color color1(200, 200, 200); // Define color1
    sf::Color color2(220, 220, 220); // Define color2
    bool isColor1 = true; // Flag to alternate between colors
    float size = 50.f; // Size of each grid cell
    std::vector<sf::RectangleShape> backgroundCells;
    for (float y = 0; y < screenHeight; y += size) {
        isColor1 = !isColor1;
        for (float x = 0; x < screenWidth; x += size) {
            sf::RectangleShape cell(sf::Vector2f(size, size)); // Create a rectangle representing a cell
            cell.setPosition(x, y); // Set position of the cell
            cell.setFillColor(isColor1 ? color1 : color2); // Alternate cell colors
            backgroundCells.emplace_back(cell); // Add cell to background vector
            isColor1 = !isColor1; // Toggle color for next cell
        }        
    }
    
    
    // Отрисовка клеток фона
    for (const auto& cell : backgroundCells) {
        window.draw(cell);
    }
    for (int i = 0; i < 5; ++i) {
        sf::CircleShape redTriangle(30.f, 3); // Радиус 30 и 3 стороны для треугольника
        redTriangle.setFillColor(sf::Color::Red);
        // Случайная позиция, исключая область вокруг кнопки
        float x, y;
        do {
            x = static_cast<float>(rand() % static_cast<int>(screenWidth - 60)) + 30;
            y = static_cast<float>(rand() % static_cast<int>(screenHeight - 60)) + 30;
        } while (std::abs(x - screenWidth / 2.f) < 150 && std::abs(y - screenHeight / 2.f) < 150);
        redTriangle.setPosition(x, y);
        window.draw(redTriangle);
    }

    // Генерация и отрисовка синих кругов
    for (int i = 0; i < 6; ++i) {
        sf::CircleShape blueCircle(20.f); // Радиус 20 для круга
        blueCircle.setFillColor(sf::Color::Blue);
        // Случайная позиция, исключая область вокруг кнопки
        float x, y;
        do {
            x = static_cast<float>(rand() % static_cast<int>(screenWidth - 40)) + 20;
            y = static_cast<float>(rand() % static_cast<int>(screenHeight - 40)) + 20;
        } while (std::abs(x - screenWidth / 2.f) < 150 && std::abs(y - screenHeight / 2.f) < 150);
        blueCircle.setPosition(x, y);
        window.draw(blueCircle);
    }
}



void MainMenu::handleInput(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (startButtonBackground.getGlobalBounds().contains(mousePosition)) {
                gameStarted = true;
            }else if (exitButtonBackground.getGlobalBounds().contains(mousePosition)) {
                window.close(); 
            }
        }
    }
}

void MainMenu::draw(sf::RenderWindow& window) {
    createBackground(window.getSize().x, window.getSize().y, window);
    window.draw(startButtonBackground);
    window.draw(startButton);
    window.draw(exitButtonBackground);
    window.draw(exitButton);
}
