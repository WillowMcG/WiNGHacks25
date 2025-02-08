#ifndef INGRKNOWLEDGE_H
#define INGRKNOWLEDGE_H
#include <iostream>

struct IngrKnowledge {
    bool knowRawDamage;
    bool knowRawHealing;
    bool knowCookedDamage;
    bool knowCookedHealing;
    bool knowNumMixes;
    bool knowCookTime;

    IngrKnowledge()
        : knowRawDamage(false), knowRawHealing(false), knowCookedDamage(false),
        knowCookedHealing(false), knowNumMixes(false), knowCookTime(false) {}

    IngrKnowledge(bool rawDamage, bool rawHealing, bool cookedDamage, bool cookedHealing,
        bool numMixes, bool cookTime)
        : knowRawDamage(rawDamage), knowRawHealing(rawHealing), knowCookedDamage(cookedDamage),
        knowCookedHealing(cookedHealing), knowNumMixes(numMixes), knowCookTime(cookTime) {}

	void printKnowledge() {
		std::cout << "Knows raw damage: " << knowRawDamage << std::endl;
		std::cout << "Knows raw healing: " << knowRawHealing << std::endl;
		std::cout << "Knows cooked damage: " << knowCookedDamage << std::endl;
		std::cout << "Knows cooked healing: " << knowCookedHealing << std::endl;
		std::cout << "Knows number of mixes: " << knowNumMixes << std::endl;
		std::cout << "Knows cook time: " << knowCookTime << std::endl;
	}
};

#endif
