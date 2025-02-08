//
// Created by Jules on 2/7/2025.
//

#ifndef SPRITES_H
#define SPRITES_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Sprites {
  vector<sf::Sprite> trees;

  sf::Sprite smallTree;
  sf::Texture smallTreeTexture;

  sf::Sprite mediumTree;
  sf::Texture mediumTreeTexture;

  sf::Sprite bigTree;
  sf::Texture bigTreeTexture;

public:
  Sprites();
  void loadTextures();
  void loadSprites();
  vector<sf::Sprite>& getTrees();
};



#endif //SPRITES_H
