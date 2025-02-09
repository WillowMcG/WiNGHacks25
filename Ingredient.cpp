#include "Ingredient.h"

Ingredient::Ingredient(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, const IngrKnowledge& ingrKnowledge,
    const IngrGiftRatings& giftRatings, const IngrStatus& ingrStatus)
    : Item(index, name, sprite, quantity), ingrProperties(ingrProperties), ingrKnowledge(ingrKnowledge), ingrGiftRatings(ingrGiftRatings) {}

const IngrProperties& Ingredient::getIngrProperties() const {
	return ingrProperties;
}


const IngrKnowledge& Ingredient::getIngrKnowledge() const {
	return ingrKnowledge;
}

const IngrGiftRatings& Ingredient::getIngrGiftRatings() const {
	return ingrGiftRatings;
}

const IngrStatus& Ingredient::getIngrStatus() const {
	return ingrStatus;
}

void Ingredient::checkStir() {
	if (ingrStatus.timesStirred > ingrProperties.numStirs) {
		ingrStatus.isRuined = true;
	}
	else if (ingrStatus.timesStirred == ingrProperties.numStirs) {
		ingrStatus.isStirred = true;
	}
}

void Ingredient::checkCook() {
	if (ingrStatus.timeCooked > ingrProperties.cookTime) {
		ingrStatus.isRuined = true;
	}
	else if (ingrStatus.timeCooked == ingrProperties.cookTime) {
		ingrStatus.isCooked = true;
	}
}

void Ingredient::stir() {
	ingrStatus.timesStirred++;
}

void Ingredient::cook() {
	ingrStatus.timeCooked++;
}

void Ingredient::printProperties() {
	std::cout << "Raw healing: " << ingrProperties.rawHealing << std::endl;
	std::cout << "Stirred healing: " << ingrProperties.stirredHealing << std::endl;
	std::cout << "Cooked healing: " << ingrProperties.cookedHealing << std::endl;
	std::cout << "Ruined healing: " << ingrProperties.ruinedHealing << std::endl;
	std::cout << "Num stirs: " << ingrProperties.numStirs << std::endl;
	std::cout << "Cook time: " << ingrProperties.cookTime << std::endl;
}

void Ingredient::printKnowledge() {
	std::cout << "Know raw healing: " << ingrKnowledge.knowRawHealing << std::endl;
	std::cout << "Know stirred healing: " << ingrKnowledge.knowStirredHealing << std::endl;
	std::cout << "Know cooked healing: " << ingrKnowledge.knowCookedHealing << std::endl;
	std::cout << "Know ruined healing: " << ingrKnowledge.knowRuinedHealing << std::endl;
	std::cout << "Know num stirs: " << ingrKnowledge.knowNumStirs << std::endl;
	std::cout << "Know cook time: " << ingrKnowledge.knowCookTime << std::endl;
}