//
// Created by Jules on 2/7/2025.
//

#include "Textures.h"

Textures::Textures() {
}

void Textures::loadTextures() {
  plant1.loadFromFile("files/images/sprites/plants_64_7.png");
  plant2.loadFromFile("files/images/sprites/plants_64_8.png");
  plant3.loadFromFile("files/images/sprites/plants_64_14.png");
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
  backgroundTextures.push_back(forest1);
  backgroundTextures.push_back(forest2);
  backgroundTextures.push_back(forest3);
  backgroundTextures.push_back(forest4);
  backgroundTextures.push_back(inventoryTexture);

  characterSL.loadFromFile("files/images/sprites/StandL.png");
  characterSR.loadFromFile("files/images/sprites/StandR.png");
  characterWL1.loadFromFile("files/images/sprites/WalkL1.png");
  characterWL2.loadFromFile("files/images/sprites/WalkL2.png");
  characterWR1.loadFromFile("files/images/sprites/WalkR1.png");
  characterWR2.loadFromFile("files/images/sprites/WalkR2.png");
  walkCycle.push_back(characterSL);
  walkCycle.push_back(characterWL1);
  walkCycle.push_back(characterWL2);
  walkCycle.push_back(characterSR);
  walkCycle.push_back(characterWR1);
  walkCycle.push_back(characterWR2);
}

vector<sf::Texture> &Textures::getPlantTextures() {
  return plantTextures;
}


vector<sf::Texture>& Textures::getItemTextures() {
  return itemTextures;
}

vector<sf::Texture>& Textures::getWalkCycle() {
  return walkCycle;
}

vector<sf::Texture>& Textures::getBackgroundTextures() {
  return backgroundTextures;
}

