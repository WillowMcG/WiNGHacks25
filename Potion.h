#ifndef POTION_H
#define POTION_H

#include <vector>
#include <unordered_map>

#include "Item.h"
#include "PtnProperties.h"
#include "PtnKnowledge.h"
#include "PtnGiftRatings.h"

class Potion : public Item {
	std::unordered_map<std::string, int> ingredients;
public:
	PtnProperties ptnProperties;
	PtnKnowledge ptnKnowledge;
	PtnGiftRatings ptnGiftRatings;

	Potion(int index, std::string name, sf::Sprite sprite, int quantity, const std::unordered_map<std::string, int>& ingredients, const PtnProperties& properties, const PtnKnowledge& ptnKnowledge,
		const PtnGiftRatings& giftRatings);

	const std::unordered_map<std::string, int>& getIngredients() const;
	PtnProperties getPtnProperties() const;
	PtnKnowledge getPtnKnowledge() const;
	PtnGiftRatings getPtnGiftRatings() const;
};

#endif