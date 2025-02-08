#pragma once

#include <string>
#include <unordered_map>

class Cooking {
	std::unordered_map<std::string, int> ingredients;
	int numMixes;
	int cookTime;
	bool isSuccess;
	int mixesCompleted;
	int timeCooked;
public:
	Cooking();
	Cooking(std::unordered_map<std::string, int> ingredients, int numMixes, int cookTime, bool isSuccess, int mixesCompleted, int timeCooked);
	std::unordered_map<std::string, int> getIngredients() const;
	int getNumMixes() const;
	int getCookTime() const;
	bool getIsSuccess() const;
	int getMixesCompleted() const;
	int getTimeCooked() const;
	void mix();
	void cook();
};

