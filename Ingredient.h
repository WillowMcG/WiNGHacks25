#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "Item.h"
#include "IngrProperties.h"
#include "IngrKnowledge.h"
#include "IngrGiftRatings.h"
#include "IngrStatus.h"

class Ingredient : public Item {
public:
	IngrProperties ingrProperties;
	IngrKnowledge ingrKnowledge;
	IngrGiftRatings ingrGiftRatings;
	IngrStatus ingrStatus;

	Ingredient(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& properties, const IngrKnowledge& ingrKnowledge,
		const IngrGiftRatings& giftRatings, const IngrStatus& ingrStatus);

	const IngrProperties& getIngrProperties() const;
	const IngrKnowledge& getIngrKnowledge() const;
	const IngrGiftRatings& getIngrGiftRatings() const;
	const IngrStatus& getIngrStatus() const;
	void checkStir();
	void checkCook();
	void stir();
	void cook();
	void printProperties();
	void printKnowledge();
};

#endif