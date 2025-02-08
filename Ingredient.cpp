#include "Ingredient.h"
#include <iostream>

Ingredient::Ingredient(int index, std::string name, sf::Sprite sprite, int quantity,
    const IngrGiftRating& giftRating, const IngrProperties& properties, const IngrKnowledge& ingrKnowledge)
    : Item(index, name, sprite, quantity), ingrGiftRating(ingrGiftRating), ingrProperties(ingrProperties), ingrKnowledge(ingrKnowledge) {}
