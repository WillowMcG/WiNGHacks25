#include <unordered_map>

#include "Potion.h"

Potion::Potion(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, 
	const IngrKnowledge& ingrKnowledge, const IngrGiftRatings& ingrGiftRatings, const IngrStatus& ingrStatus, 
	const std::unordered_map<std::string, int>& ingredients, bool knowIngredients, bool isComplete)
	: Ingredient(index, name, sprite, quantity, ingrProperties, ingrKnowledge, ingrGiftRatings, ingrStatus), ingredients(ingredients), 
	knowIngredients(knowIngredients), isComplete(isComplete) {}

const std::unordered_map<std::string, int>& Potion::getIngredients() const {
	return ingredients;
}

bool Potion::getKnowIngredients() const {
	return knowIngredients;
}

bool Potion::getIsComplete() const {
	return isComplete;
}