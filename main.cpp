//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include "Sprites.h"
#include "DrawForest.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <random>
#include <ctime>

void setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

vector<int> randomTrees() {
    vector<int> positions;
    for (int i = 0; i < 8; i++) {
        positions.push_back(rand() % 4);
    }

    return positions;
}

int gameLoop(sf::RenderWindow& window, int width, int height) {
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Red);

    //the screen will be set into eight sections which may contain a small, medium, big, or no tree
    //this is randomized

    //Draw the initial forest
    sf::RectangleShape smallTree(sf::Vector2f(100, 800));
    smallTree.setFillColor(sf::Color::Black);
    smallTree.setPosition(width/8, 0);

    sf::RectangleShape mediumTree(sf::Vector2f(150, 900));
    mediumTree.setFillColor(sf::Color::Black);
    mediumTree.setPosition(width/4, 0);

    sf::RectangleShape largeTree(sf::Vector2f(200, 950));
    largeTree.setFillColor(sf::Color::Black);
    largeTree.setPosition(3*width/8, 0);

    sf::RectangleShape smallTree2(sf::Vector2f(100, 800));
    smallTree2.setFillColor(sf::Color::Black);
    smallTree2.setPosition(width/2, 0);

    sf::RectangleShape largeTree2(sf::Vector2f(200, 950));
    largeTree2.setFillColor(sf::Color::Black);
    largeTree2.setPosition(5*width/8, 0);

    sf::RectangleShape smallTree3(sf::Vector2f(100, 800));
    smallTree3.setFillColor(sf::Color::Black);
    smallTree3.setPosition(3*width/4, 0);

    sf::RectangleShape mediumTree2(sf::Vector2f(150, 900));
    mediumTree2.setFillColor(sf::Color::Black);
    mediumTree2.setPosition(7*width/8, 0);

    sf::RectangleShape character(sf::Vector2f(256, 256));
    character.setFillColor(sf::Color::Green);
    character.setOrigin(128, 128);
    character.setPosition(width-width/12, height-height/8);

    sf::RectangleShape i1(sf::Vector2f(128, 128));
    i1.setFillColor(sf::Color::Green);
    i1.setPosition(50, 50);

    sf::RectangleShape i2(sf::Vector2f(128, 128));
    i2.setFillColor(sf::Color::Green);
    i2.setPosition(100+128, 50);

    sf::RectangleShape i3(sf::Vector2f(128, 128));
    i3.setFillColor(sf::Color::Green);
    i3.setPosition(150+2*128, 50);

    sf::RectangleShape i4(sf::Vector2f(128, 128));
    i4.setFillColor(sf::Color::Green);
    i4.setPosition(200+3*128, 50);

    sf::Clock clock;

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return -1;
            }
            float deltaTime = clock.restart().asSeconds();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                character.move(-10, 0.f);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                character.move(10, 0.f);
            }
        }

        if (character.getPosition().x <= 0) {

        }

        window.clear();
        window.draw(background);
        window.draw(smallTree);
        window.draw(mediumTree);
        window.draw(largeTree);
        window.draw(smallTree2);
        window.draw(largeTree2);
        window.draw(mediumTree2);
        window.draw(smallTree3);
        window.draw(character);
        window.draw(i1);
        window.draw(i2);
        window.draw(i3);
        window.draw(i4);
        window.display();
    }
}

int main() {
    sf::Font body;
    body.loadFromFile("files/SummerPixel.ttf"); //Font - can be changed later

    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "Plant Game");
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Red);

    // sf::RectangleShape menu(sf::Vector2f(1200, 880));
    // menu.setPosition(100, 100);

    sf::Text start;
    start.setString("- Press E To Start -");
    start.setFont(body);
    start.setCharacterSize(40);
    setText(start, width/2, height/2);

    int run = 0; //is game running?

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::E) {
                    start.setString("Game Started");
                    run = gameLoop(window, width, height);
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(start);
        window.display();
    }
    return 0;
}