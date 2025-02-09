//
// Created by Jules on 2/8/2025.
//

#include "Textbox.h"



Textbox::Textbox(float x, float y, sf::Font& font, int size, Textures& textures, string text) {
  isOpen = false;
  message.setString(text);
  message.setFont(font);
  message.setCharacterSize(size);
  setText(message, x, y);
  }

void Textbox::setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void Textbox::drawTextbox(sf::RenderWindow& window) {
  window.draw(background);
  window.draw(message);
  }

void Textbox::open() {
  isOpen = true;
  }

void Textbox::close() {
  isOpen = false;
  }

bool Textbox::checkOpen() {
  return isOpen;
  }