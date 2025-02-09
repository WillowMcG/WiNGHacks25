//
// Created by Jules on 2/7/2025.
//

#include "Textures.h"

Textures::Textures() {
}

void Textures::loadTextures() {
  plant1.loadFromFile("files/images/sprites/Djorchertwitz.png");
  plant2.loadFromFile("files/images/sprites/Hygogix.png");
  plant3.loadFromFile("files/images/sprites/Spindlewort.png");
  plantTextures.push_back(plant1);
  plantTextures.push_back(plant2);
  plantTextures.push_back(plant3);

  cauldronTexture.loadFromFile("files/images/sprites/Cauldron_Icon.png");
  cauldronLightTexture.loadFromFile("files/images/sprites/Cauldron_Icon_Highlight.png");
  itemTextures.push_back(cauldronTexture);
  itemTextures.push_back(cauldronLightTexture);

  forest1.loadFromFile("files/images/backgrounds/forest1.png");
  forest2.loadFromFile("files/images/backgrounds/forest2.png");
  forest3.loadFromFile("files/images/backgrounds/forest3.png");
  forest4.loadFromFile("files/images/backgrounds/forest4.png");
  inventoryTexture.loadFromFile("files/images/backgrounds/Inventory.png");
  infoBackground.loadFromFile("files/images/backgrounds/InfoBackground.png");
  backgroundTextures.push_back(forest1);
  backgroundTextures.push_back(forest2);
  backgroundTextures.push_back(forest3);
  backgroundTextures.push_back(forest4);
  backgroundTextures.push_back(inventoryTexture);
  backgroundTextures.push_back(infoBackground);
}

vector<sf::Texture> &Textures::getPlantTextures() {
  return plantTextures;
}

vector<sf::Texture>& Textures::getItemTextures() {
  return itemTextures;
}

vector<sf::Texture>& Textures::getBackgroundTextures() {
  return backgroundTextures;
}

