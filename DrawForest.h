//
// Created by Jules on 2/7/2025.
//

#ifndef DRAWFOREST_H
#define DRAWFOREST_H

#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class DrawForest {
  vector<sf::Sprite>& trees;
public:
   DrawForest(vector<sf::Sprite>& trees);
   void Render(sf::Window& window, int width, int height);
};



#endif //DRAWFOREST_H
