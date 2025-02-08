#include <unordered_map>

#include "Potion.h"

Potion::Potion(int index, std::string name, sf::Sprite sprite, int quantity, const std::unordered_map<std::string, int>& ingredients,
	const PtnProperties& properties, const PtnKnowledge& ptnKnowledge, const PtnGiftRatings& giftRatings)
	: Item(index, name, sprite, quantity), ingredients(ingredients), ptnProperties(properties), ptnKnowledge(ptnKnowledge),
	ptnGiftRatings(giftRatings) {}

const std::unordered_map<std::string, int>& Potion::getIngredients() const {
	return ingredients;
}

PtnProperties Potion::getPtnProperties() const {
	return ptnProperties;
}

PtnKnowledge Potion::getPtnKnowledge() const {
	return ptnKnowledge;
}

PtnGiftRatings Potion::getPtnGiftRatings() const {
	return ptnGiftRatings;
}