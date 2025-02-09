//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include "Textures.h"
#include "Animation.h"
#include "Textbox.h"
#include "StatsManager.h"
#include "InventoryManager.h"
#include "Item.h"
#include "Ingredient.h"
#include "IngrGiftRatings.h"
#include "IngrProperties.h"
#include "IngrKnowledge.h"
#include "IngrStatus.h"
#include "Potion.h"
#include "Cooking.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
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
        string plantType = (plantChoice == 0) ? "Djorchertwitz" :
                           (plantChoice == 1) ? "Type 2" : "Type 3";

        plants.push_back({plantType, pos});
        pos += 200 + rand() % 300;
    }
    return plants;
}

void texturePlant(sf::Sprite& plant, string type, Textures& textures) {
    if (type == "Djorchertwitz") {
        plant.setTexture(textures.getPlantTextures().at(0));
    } else if (type == "Type 2") {
        plant.setTexture(textures.getPlantTextures().at(1));
    } else if (type == "Type 3") {
        plant.setTexture(textures.getPlantTextures().at(2));
    }
}

void initializePlants(InventoryManager& inventory_manager) {
    sf::Texture texture;
    texture.loadFromFile("files/images/sprites/Cauldron_Icon.png");
    sf::Sprite djorchSprite(texture);
    sf::Sprite sprite2(texture);
    sf::Sprite sprite3(texture);

    // People: Mushroom Man, Witch, Wolfhound

    IngrProperties propertiesDjorch(7, 3, -2, -20, 5, 20);
    IngrKnowledge knowledgeDjorch(false, false, false, false, false, false);
    IngrGiftRatings giftRatingDjorch({-5, 11, 0});
    IngrStatus statusDjorch(false, false, false, 0, 0);
    Ingredient djorchertwitz = Ingredient(0, "Djorchertwitz", djorchSprite, 1, propertiesDjorch, knowledgeDjorch, giftRatingDjorch, statusDjorch);
    inventory_manager.items.push_back(djorchertwitz);

    IngrProperties propertiesType2(8, 12, 15, -10, 8, 15);
    IngrKnowledge knowledgeType2(false, false, false, false, false, false);
    IngrGiftRatings giftRatingType2({5, -10, 8});
    IngrStatus statusType2(false, false, false, 0, 0);
    Ingredient type2 = Ingredient(0, "Type 2", sprite2, 1, propertiesType2, knowledgeType2, giftRatingType2, statusType2);
    inventory_manager.items.push_back(type2);

    IngrProperties propertiesType3(0, 0, 0, 0, 0, 0);
    IngrKnowledge knowledgeType3(false, false, false, false, false, false);
    IngrGiftRatings giftRatingType3({0, 0, 0});
    IngrStatus statusType3(false, false, false, 0, 0);
    Ingredient type3 = Ingredient(0, "Type 3", sprite3, 1, propertiesType3, knowledgeType3, giftRatingType3, statusType3);
    inventory_manager.items.emplace_back(type3);
}

void initializeInventory(InventoryManager& inventory_manager) {}

int gameLoop(sf::RenderWindow& window, float width, float height, Textures& textures, sf::Font& body) {
    InventoryManager plantDebug;
    initializePlants(plantDebug);
    sf::Clock clock;

    InventoryManager playerInventory;
    initializeInventory(playerInventory);

    sf::Sprite background;
    background.setTexture(textures.getBackgroundTextures().at(0));
    int backgroundNum = 0;

    vector<pair<string, int>> plants = genPlants();

    sf::Sprite inventoryBackground(textures.getBackgroundTextures().at(4));
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
    plant1.setScale(2,2);
    bool p1 = true;
    plant2.setPosition(plants.at(1).second, plantHeight);
    plant2.setScale(2,2);
    texturePlant(plant2, plants.at(1).first, textures);
    bool p2 = true;
    plant3.setPosition(plants.at(2).second, plantHeight);
    plant3.setScale(2,2);
    texturePlant(plant3, plants.at(2).first, textures);
    bool p3 = true;
    plant4.setPosition(plants.at(3).second, plantHeight);
    plant4.setScale(2,2);
    texturePlant(plant4, plants.at(3).first, textures);
    bool p4 = true;
    plant5.setPosition(plants.at(4).second, plantHeight);
    texturePlant(plant5, plants.at(4).first, textures);
    plant5.setScale(2,2);
    bool p5 = true;

    Textbox harvestPlant(width/2, height/4, body, 40, textures, "Press W to Harvest");
    harvestPlant.open();

    Textbox harvestDjorch(width/2, height/4, body, 40, textures, "Djorchertwitz Added to Inventory");
    Textbox harvest2(width/2, height/4, body, 40, textures, "Type 2 Added to Inventory");
    Textbox harvest3(width/2, height/4, body, 40, textures, "Type 3 Added to Inventory");

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

    int elapsed=0;

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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    int xpos = character.getPosition().x;
                    if (xpos > plant1.getPosition().x - 80 && xpos < plant1.getPosition().x + 80 && p1) {
                        p1 = false;
                        clock.restart();
                        if (plants.at(0).first == "Djorchertwitz") {
                            playerInventory.pickUpItem(plantDebug.getItem("Djorchertwitz"));
                            harvestDjorch.open();
                            harvest2.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else if (plants.at(0).first == "Type 2") {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 2"));
                            harvest2.open();
                            harvestDjorch.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 3"));
                            harvest3.open();
                            harvestDjorch.close();
                            harvest2.close();
                            harvestPlant.close();
                        }
                    } else if (xpos > plant2.getPosition().x - 80 && xpos < plant2.getPosition().x + 80 && p2) {
                        p2 = false;
                        clock.restart();
                        if (plants.at(1).first == "Djorchertwitz") {
                            playerInventory.pickUpItem(plantDebug.getItem("Djorchertwitz"));
                            harvestDjorch.open();
                            harvest2.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else if (plants.at(1).first == "Type 2") {
                            playerInventory.pickUpItem(plantDebug.getItem("Djorchertwitz"));
                            harvest2.open();
                            harvestDjorch.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 3"));
                            harvest3.open();
                            harvestDjorch.close();
                            harvest2.close();
                            harvestPlant.close();
                        }
                    } else if (xpos > plant3.getPosition().x - 80 && xpos < plant3.getPosition().x + 80 && p3) {
                        p3 = false;
                        clock.restart();
                        if (plants.at(2).first == "Djorchertwitz") {
                            playerInventory.pickUpItem(plantDebug.getItem("Djorchertwitz"));
                            harvestDjorch.open();
                            harvest2.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else if (plants.at(2).first == "Type 2") {
                            playerInventory.pickUpItem(plantDebug.getItem("Djorchertwitz"));
                            harvest2.open();
                            harvestDjorch.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 3"));
                            harvest3.open();
                            harvestDjorch.close();
                            harvest2.close();
                            harvestPlant.close();
                        }
                    } else if (xpos > plant4.getPosition().x - 80 && xpos < plant4.getPosition().x + 80 & p4) {
                        p4 = false;
                        clock.restart();
                        if (plants.at(3).first == "Djorchertwitz") {
                            playerInventory.pickUpItem(plantDebug.getItem("Djorchertwitz"));
                            harvestDjorch.open();
                            harvest2.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else if (plants.at(3).first == "Type 2") {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 2"));
                            harvest2.open();
                            harvestDjorch.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 3"));
                            harvest3.open();
                            harvestDjorch.close();
                            harvest2.close();
                            harvestPlant.close();
                        }
                    } else if (xpos > plant5.getPosition().x - 80 && xpos < plant5.getPosition().x + 80 && p5) {
                        p5 = false;
                        clock.restart();
                        if (plants.at(4).first == "Djorchertwitz") {
                            playerInventory.pickUpItem(plantDebug.getItem("Djorchertwitz"));
                            harvestDjorch.open();
                            harvest2.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else if (plants.at(4).first == "Type 2") {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 2"));
                            harvest2.open();
                            harvestDjorch.close();
                            harvest3.close();
                            harvestPlant.close();
                        } else {
                            playerInventory.pickUpItem(plantDebug.getItem("Type 3"));
                            harvest3.open();
                            harvestDjorch.close();
                            harvest2.close();
                            harvestPlant.close();
                        }
                    }
                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !inventoryOpen) {
                inventoryOpen = true;
                playerInventory.print();
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
                harvestPlant.close();

                plants = genPlants();

                plant1.setPosition(plants.at(0).second, plantHeight);
                texturePlant(plant1, plants.at(0).first, textures);
                p1 = true;
                plant2.setPosition(plants.at(1).second, plantHeight);
                texturePlant(plant2, plants.at(1).first, textures);
                p2 = true;
                plant3.setPosition(plants.at(2).second, plantHeight);
                texturePlant(plant3, plants.at(2).first, textures);
                p3 = true;
                plant4.setPosition(plants.at(3).second, plantHeight);
                texturePlant(plant4, plants.at(3).first, textures);
                p4 = true;
                plant5.setPosition(plants.at(4).second, plantHeight);
                texturePlant(plant5, plants.at(4).first, textures);
                p5 = true;

                if (character.getPosition().x < 0) {
                    character.setPosition(1920, height-height/4);
                } else {
                    character.setPosition(0, height-height/4);
                }
            }

            window.clear();
            window.draw(background);
            if (p1) {
                window.draw(plant1);
            }
            if (p2) {
                window.draw(plant2);
            }
            if (p3) {
                window.draw(plant3);
            }
            if (p4) {
                window.draw(plant4);
            }
            if (p5) {
                window.draw(plant5);
            }
            window.draw(character);
            if (harvestPlant.checkOpen() && elapsed <= 5) {
                harvestPlant.drawTextbox(window);
            } else {
                harvestPlant.close();
            }
            if (harvestDjorch.checkOpen() && elapsed <= 5) {
                harvestDjorch.drawTextbox(window);
            } else {
                harvestDjorch.close();
            }
            if (harvest2.checkOpen() && elapsed <= 5) {
                harvest2.drawTextbox(window);
            } else {
                harvest2.close();
            }
            if (harvest3.checkOpen() && elapsed <= 5) {
                harvest3.drawTextbox(window);
            } else {
                harvest3.close();
            }
            if (inventoryOpen) {
                window.draw(inventoryBackground);
            }
            window.display();
        }

    }
    return 0;
}



int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 3;

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
                    run = gameLoop(window, width, height, textures, body);
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
