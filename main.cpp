//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include <SFML/Graphics.hpp>


void drawForest(sf::RenderWindow& window, int width, int height) {

}

int main() {
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "Plant Game");
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Red);

    // sf::RectangleShape menu(sf::Vector2f(1200, 880));
    // menu.setPosition(100, 100);

    sf::Text start;
    start.setString("- Press E To Start -");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(background);
        window.draw(menu);
        window.display();
    }
    return 0;
}