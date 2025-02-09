//
// Created by Jules on 2/8/2025.
//

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Textures.h"
using namespace std;

class Textbox {
  string text;
  sf::Text message;
  sf::Font font;
  sf::Sprite background;
  bool isOpen;
public:
  Textbox(float width, float height, sf::Font& font, int size, Textures& textures, string text);
  void setText(sf::Text &text, float x, float y);
  void drawTextbox(sf::RenderWindow& window);
  void open();
  void close();
  bool checkOpen();
};



#endif //TEXTBOX_H
