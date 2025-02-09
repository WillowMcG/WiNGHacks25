#include <unordered_map>

#include "Cooking.h"

Cooking::Cooking() {
	ingredients = std::unordered_map<std::string, int>();
	numMixes = 0;
	cookTime = 0;
	isSuccess = false;
	mixesCompleted = 0;
	timeCooked = 0;
}

Cooking::Cooking(std::unordered_map<std::string, int> ingredients, int numMixes, int cookTime, bool isSuccess, int mixesCompleted, int timeCooked) {
	this->ingredients = ingredients;
	this->numMixes = numMixes;
	this->cookTime = cookTime;
	this->isSuccess = isSuccess;
	this->mixesCompleted = mixesCompleted;
	this->timeCooked = timeCooked;
}

std::unordered_map<std::string, int> Cooking::getIngredients() const {
	return ingredients;
}

int Cooking::getNumMixes() const {
	return numMixes;
}

int Cooking::getCookTime() const {
	return cookTime;
}

bool Cooking::getIsSuccess() const {
	return isSuccess;
}

int Cooking::getMixesCompleted() const {
	return mixesCompleted;
}

int Cooking::getTimeCooked() const {
	return timeCooked;
}

void Cooking::mix() {
	numMixes++;
}

void Cooking::cook() {
	timeCooked++;
}