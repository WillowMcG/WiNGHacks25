#ifndef INGRKNOWLEDGE_H
#define INGRKNOWLEDGE_H
#include <iostream>

struct IngrKnowledge {
    bool knowRawHealing;
    bool knowCookedHealing;
    bool knowNumMixes;
    bool knowCookTime;

    IngrKnowledge()
        : knowRawHealing(false),
        knowCookedHealing(false), knowNumMixes(false), knowCookTime(false) {}

    IngrKnowledge(bool rawDamage, bool rawHealing, bool cookedDamage, bool cookedHealing,
        bool numMixes, bool cookTime)
        : knowRawHealing(rawHealing),
        knowCookedHealing(cookedHealing), knowNumMixes(numMixes), knowCookTime(cookTime) {}

	void printKnowledge() {
		std::cout << "Knows raw healing: " << knowRawHealing << std::endl;
		std::cout << "Knows cooked healing: " << knowCookedHealing << std::endl;
		std::cout << "Knows number of mixes: " << knowNumMixes << std::endl;
		std::cout << "Knows cook time: " << knowCookTime << std::endl;
	}
};

#endif
