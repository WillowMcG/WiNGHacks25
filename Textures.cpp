//
// Created by Jules on 2/7/2025.
//

#include "Textures.h"

Textures::Textures() {
}

void Textures::loadTextures() {
  cauldronTexture.loadFromFile("files/images/sprites/Cauldron_Icon copy.png");
  itemTextures.push_back(cauldronTexture);
  cauldronLightTexture.loadFromFile("files/images/sprites/Cauldron_Icon_Highlight copy.png");
  itemTextures.push_back(cauldronLightTexture);
  inventoryTexture.loadFromFile("files/images/backgrounds/Inventory.png");
  backgroundTextures.push_back(inventoryTexture);
}

vector<sf::Texture>& Textures::getItemTextures() {
  return itemTextures;
}

vector<sf::Texture>& Textures::getBackgroundTextures() {
  return backgroundTextures;
}

