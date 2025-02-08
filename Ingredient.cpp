#include "Ingredient.h"
#include <iostream>

Ingredient::Ingredient(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, const IngrKnowledge& ingrKnowledge,
    const IngrGiftRating& giftRating)
    : Item(index, name, sprite, quantity), ingrProperties(ingrProperties), ingrKnowledge(ingrKnowledge), ingrGiftRating(ingrGiftRating) {}

IngrProperties Ingredient::getIngrProperties() const {
	return ingrProperties;
}

IngrKnowledge Ingredient::getIngrKnowledge() const {
	return ingrKnowledge;
}

IngrGiftRating Ingredient::getIngrGiftRating() const {
	return ingrGiftRating;
}