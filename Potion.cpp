#include <unordered_map>

#include "Potion.h"

Potion::Potion(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& ingrProperties, 
	const IngrKnowledge& ingrKnowledge, const IngrGiftRatings& ingrGiftRatings, const IngrStatus& ingrStatus, 
	const std::unordered_map<std::string, int>& ingredients, bool knowIngredients, bool isComplete)
	: Item(index, name, sprite, quantity), ingrProperties(ingrProperties), ingrKnowledge(ingrKnowledge), ingrGiftRatings(ingrGiftRatings), ingrStatus(ingrStatus), ingredients(ingredients),
	knowIngredients(knowIngredients), isComplete(isComplete) {}

const IngrProperties& Potion::getIngrProperties() const {
	return ingrProperties;
}


const IngrKnowledge& Potion::getIngrKnowledge() const {
	return ingrKnowledge;
}

const IngrGiftRatings& Potion::getIngrGiftRatings() const {
	return ingrGiftRatings;
}

const IngrStatus& Potion::getIngrStatus() const {
	return ingrStatus;
}

void Potion::checkStir() {
	if (ingrStatus.timesStirred > ingrProperties.numStirs) {
		ingrStatus.isRuined = true;
	}
	else if (ingrStatus.timesStirred == ingrProperties.numStirs) {
		ingrStatus.isStirred = true;
	}
}

void Potion::checkCook() {
	if (ingrStatus.timeCooked > ingrProperties.cookTime) {
		ingrStatus.isRuined = true;
	}
	else if (ingrStatus.timeCooked == ingrProperties.cookTime) {
		ingrStatus.isCooked = true;
	}
}

void Potion::stir() {
	ingrStatus.timesStirred++;
}

void Potion::cook() {
	ingrStatus.timeCooked++;
}

void Potion::printProperties() {
	std::cout << "Raw healing: " << ingrProperties.rawHealing << std::endl;
	std::cout << "Stirred healing: " << ingrProperties.stirredHealing << std::endl;
	std::cout << "Cooked healing: " << ingrProperties.cookedHealing << std::endl;
	std::cout << "Ruined healing: " << ingrProperties.ruinedHealing << std::endl;
	std::cout << "Num stirs: " << ingrProperties.numStirs << std::endl;
	std::cout << "Cook time: " << ingrProperties.cookTime << std::endl;
}

void Potion::printKnowledge() {
	std::cout << "Know raw healing: " << ingrKnowledge.knowRawHealing << std::endl;
	std::cout << "Know stirred healing: " << ingrKnowledge.knowStirredHealing << std::endl;
	std::cout << "Know cooked healing: " << ingrKnowledge.knowCookedHealing << std::endl;
	std::cout << "Know ruined healing: " << ingrKnowledge.knowRuinedHealing << std::endl;
	std::cout << "Know num stirs: " << ingrKnowledge.knowNumStirs << std::endl;
	std::cout << "Know cook time: " << ingrKnowledge.knowCookTime << std::endl;
}

const std::unordered_map<std::string, int>& Potion::getIngredients() const {
	//return ingredients;
	return ingrGiftRatings.ratings;
}

bool Potion::getKnowIngredients() const {
	return knowIngredients;
}

bool Potion::getIsComplete() const {
	return isComplete;
}

bool Potion::checkComplete(const IngrProperties& ingrProperties, const IngrStatus& ingrStatus) {
	if (ingrStatus.timesStirred >= ingrProperties.numStirs && ingrStatus.timeCooked >= ingrProperties.cookTime) {
		isComplete = true;
	}
	return false;
}