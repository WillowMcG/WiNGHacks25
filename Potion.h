/*#ifndef POTION_H
#define POTION_H

#include <vector>
#include <unordered_map>

#include "Ingredient.h"

class Potion : public Ingredient {
public:

	std::unordered_map<std::string, int> ingredients;
	bool knowIngredients;
	bool isComplete;

	Potion(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, const IngrKnowledge& ingrKnowledge,
		const IngrGiftRatings& ingrGiftRatings, const IngrStatus& ingrStatus, const std::unordered_map<std::string, int>& ingredients,
		bool knowIngredients, bool isComplete);

	const std::unordered_map<std::string, int>& getIngredients() const;
	bool getKnowIngredients() const;
	bool getIsComplete() const;
	bool checkComplete(const IngrProperties& ingrProperties, const IngrStatus& ingrStatus);
};

#endif*/

#ifndef POTION_H
#define POTION_H

#include <vector>
#include <unordered_map>

#include "Item.h"
#include "IngrProperties.h"
#include "IngrKnowledge.h"
#include "IngrGiftRatings.h"
#include "IngrStatus.h"

class Potion : public Item {
public:

	IngrProperties ingrProperties;
	IngrKnowledge ingrKnowledge;
	IngrGiftRatings ingrGiftRatings;
	IngrStatus ingrStatus;

	std::unordered_map<std::string, int> ingredients;
	bool knowIngredients;
	bool isComplete;
	

	Potion(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, const IngrKnowledge& ingrKnowledge,
		const IngrGiftRatings& ingrGiftRatings, const IngrStatus& ingrStatus, const std::unordered_map<std::string, int>& ingredients,
		bool knowIngredients, bool isComplete);

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
	const std::unordered_map<std::string, int>& getIngredients() const;
	bool getKnowIngredients() const;
	bool getIsComplete() const;
	bool checkComplete(const IngrProperties& ingrProperties, const IngrStatus& ingrStatus);
};

#endif