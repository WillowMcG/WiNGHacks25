//
// Created by Jules on 2/7/2025.
//

#ifndef TEXTURES_H
#define TEXTURES_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Textures {
  vector<sf::Texture> itemTextures;
  vector<sf::Texture> walkCycle;
  vector<sf::Texture> backgroundTextures;

  sf::Texture cauldronTexture;
  sf::Texture cauldronLightTexture;

  sf::Texture characterSR;
  sf::Texture characterSL;
  sf::Texture characterWR1;
  sf::Texture characterWR2;
  sf::Texture characterWL1;
  sf::Texture characterWL2;

  sf::Texture inventoryTexture;

public:
  Textures();
  void loadTextures();
  vector<sf::Texture>& getItemTextures();
  vector<sf::Texture>& getWalkCycle();
  vector<sf::Texture>& getBackgroundTextures();
};



#endif //TEXTURES_H
