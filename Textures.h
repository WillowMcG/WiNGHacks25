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
  vector<sf::Texture> backgroundTextures;

  sf::Texture cauldronTexture;
  sf::Texture cauldronLightTexture;

  sf::Texture inventoryTexture;

public:
  Textures();
  void loadTextures();
  vector<sf::Texture>& getItemTextures();
  vector<sf::Texture>& getBackgroundTextures();
};



#endif //TEXTURES_H
