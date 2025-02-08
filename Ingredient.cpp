#include "Ingredient.h"

Ingredient::Ingredient(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, const IngrKnowledge& ingrKnowledge,
    const IngrGiftRatings& giftRatings)
    : Item(index, name, sprite, quantity), ingrProperties(ingrProperties), ingrKnowledge(ingrKnowledge), ingrGiftRatings(ingrGiftRatings) {}

IngrProperties Ingredient::getIngrProperties() const {
	return ingrProperties;
}

IngrKnowledge Ingredient::getIngrKnowledge() const {
	return ingrKnowledge;
}

IngrGiftRatings Ingredient::getIngrGiftRatings() const {
	return ingrGiftRatings;
}