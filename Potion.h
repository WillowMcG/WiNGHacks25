#ifndef POTION_H
#define POTION_H

#include <vector>
#include <unordered_map>

#include "Ingredient.h"

class Potion : public Ingredient {
	std::unordered_map<std::string, int> ingredients;
	bool knowIngredients;
	bool isComplete;
public:

	Potion(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, const IngrKnowledge& ingrKnowledge,
		const IngrGiftRatings& ingrGiftRatings, const IngrStatus& ingrStatus, const std::unordered_map<std::string, int>& ingredients,
		bool knowIngredients, bool isComplete);

	const std::unordered_map<std::string, int>& getIngredients() const;
	bool getKnowIngredients() const;
	bool getIsComplete() const;
	bool checkComplete(const IngrProperties& ingrProperties, const IngrStatus& ingrStatus);
};

#endif