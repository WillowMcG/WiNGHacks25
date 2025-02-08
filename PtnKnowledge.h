#ifndef PTNKNOWLEDGE_H
#define PTNKNOWLEDGE_H

#include <iostream>

struct PtnKnowledge {
    bool knowRawHealing;
    bool knowCookedHealing;
	bool knowNumMixes;
	bool knowCookTime;
	bool knowIngredients;

    PtnKnowledge()
        : knowRawHealing(false), knowCookedHealing(false), knowNumMixes(false), knowCookTime(false), knowIngredients(false) {}

    PtnKnowledge(bool rawHealing, bool cookedHealing, bool numMixes, bool cookTime, bool knowIngredients)
        : knowRawHealing(rawHealing), knowCookedHealing(cookedHealing), knowNumMixes(numMixes), knowCookTime(cookTime),
        knowIngredients(knowIngredients) {}

    void printKnowledge() {
        std::cout << "Knows raw healing: " << knowRawHealing << std::endl;
        std::cout << "Knows cooked healing: " << knowCookedHealing << std::endl;
        std::cout << "Knows number of mixes: " << knowNumMixes << std::endl;
        std::cout << "Knows cook time: " << knowCookTime << std::endl;
		std::cout << "Knows ingredients: " << knowIngredients << std::endl;
    }
};

#endif
