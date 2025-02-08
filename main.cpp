//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include "Textures.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <tuple>

void setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

vector<pair<string, int>> genPlants() {
    vector<pair<string, int>> plants;
    int plantNum = 5;
    int pos = rand() % 200;
    pair<string, int> plantInfo;

    for (int i = 0; i < plantNum; i++) {
        int plantChoice = rand() % 3;
        string plantType = (plantChoice == 0) ? "Type 1" :
                           (plantChoice == 1) ? "Type 2" : "Type 3";

        plants.push_back({plantType, pos});
        pos += 200 + rand() % 300;
    }
    return plants;
}

void texturePlant(sf::Sprite& plant, string type, Textures& textures) {
    if (type == "Type 1") {
        plant.setTexture(textures.getPlantTextures().at(0));
    } else if (type == "Type 2") {
        plant.setTexture(textures.getPlantTextures().at(1));
    } else if (type == "Type 3") {
        plant.setTexture(textures.getPlantTextures().at(2));
    }
}

int gameLoop(sf::RenderWindow& window, int width, int height, Textures& textures) {
    Clock clock;
    double elapsed = clock.restart().asSeconds();

    sf::Sprite background;
    background.setTexture(textures.getBackgroundTextures().at(0));
    int backgroundNum = 0;

    vector<pair<string, int>> plants = genPlants();

    sf::Sprite inventoryBackground;
    inventoryBackground.setTexture(textures.getBackgroundTextures().at(1));
    inventoryBackground.setOrigin(width/2, height/2);
    inventoryBackground.setPosition(width/2, height/2);

    sf::Sprite character;
    character.setOrigin(256, 256);
    character.setPosition(width-width/8, height-height/4);

    int plantHeight = height-height/4;

    sf::Sprite plant1;
    sf::Sprite plant2;
    sf::Sprite plant3;
    sf::Sprite plant4;
    sf::Sprite plant5;

    plant1.setPosition(plants.at(0).second, plantHeight);
    texturePlant(plant1, plants.at(0).first, textures);
    plant2.setPosition(plants.at(1).second, plantHeight);
    texturePlant(plant2, plants.at(1).first, textures);
    plant3.setPosition(plants.at(2).second, plantHeight);
    texturePlant(plant3, plants.at(2).first, textures);
    plant4.setPosition(plants.at(3).second, plantHeight);
    texturePlant(plant4, plants.at(3).first, textures);
    plant5.setPosition(plants.at(4).second, plantHeight);
    texturePlant(plant5, plants.at(4).first, textures);

    sf::Texture sprite_sheet;
    Animation animations;

    if (!(sprite_sheet.loadFromFile("files/images/sprites/sprite_sheet.png")))
    {
        cout << "Could Not Load File..." << endl;
    }

    character.setTexture(sprite_sheet);

    animations.addAnimation("walkLeft", sprite_sheet, {6, 1}, {512, 512}, {3,0}, 8, {3,0});
    animations.setAnimationStartingIndex("walkLeft", {3,0});
    animations.setAnimationEndingIndex("walkLeft", {5,0});
    animations.addAnimation("walkRight", sprite_sheet, {6,1}, {512, 512}, {3,0}, 12, {0,0});
    animations.setAnimationStartingIndex("walkRight", {0,0});
    animations.setAnimationEndingIndex("walkRight", {2, 0});

    bool inventoryOpen = false;
    bool isMoving = false;

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return -1;
            }
            if (!inventoryOpen) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    character.move(-8, 0.f);
                    animations.update("walkLeft", character);
                    isMoving = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    character.move(8, 0.f);
                    animations.update("walkRight", character);
                    isMoving = true;
                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !inventoryOpen) {
                inventoryOpen = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && inventoryOpen) {
                inventoryOpen = false;
            }

            if (!isMoving) {
                animations.resetAnimationIndex("walkLeft");
                animations.resetAnimationIndex("walkRight");
            }

            if (character.getPosition().x < 0 || character.getPosition().x > 1920) {
                int newBackground = rand() % 4;
                while (newBackground == backgroundNum) {
                    newBackground = rand() % 4;
                }
                backgroundNum = newBackground;
                background.setTexture(textures.getBackgroundTextures().at(backgroundNum));

                plants = genPlants();

                plant1.setPosition(plants.at(0).second, plantHeight);
                texturePlant(plant1, plants.at(0).first, textures);
                plant2.setPosition(plants.at(1).second, plantHeight);
                texturePlant(plant2, plants.at(1).first, textures);
                plant3.setPosition(plants.at(2).second, plantHeight);
                texturePlant(plant3, plants.at(2).first, textures);
                plant4.setPosition(plants.at(3).second, plantHeight);
                texturePlant(plant4, plants.at(3).first, textures);
                plant5.setPosition(plants.at(4).second, plantHeight);
                texturePlant(plant5, plants.at(4).first, textures);

                if (character.getPosition().x < 0) {
                    character.setPosition(1920, height-height/4);
                } else {
                    character.setPosition(0, height-height/4);
                }
            }

            window.clear();
            window.draw(background);
            window.draw(plant1);
            window.draw(plant2);
            window.draw(plant3);
            window.draw(plant4);
            window.draw(plant5);
            window.draw(character);
            if (inventoryOpen) {
                window.draw(inventoryBackground);
                plants = genPlants();
            }
            window.display();
        }

    }
    return 0;
}

int main() {
    sf::Font body;
    body.loadFromFile("files/SummerPixel.ttf"); //Font - can be changed later

    Textures textures;
    textures.loadTextures();

    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "Plant Game");
    sf::Sprite background;

    sf::Text start;
    start.setString("- Press [Enter] To Start -");
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
                if (event.key.code == sf::Keyboard::Enter) {
                    run = gameLoop(window, width, height, textures);
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