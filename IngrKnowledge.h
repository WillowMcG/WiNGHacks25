#ifndef INGRKNOWLEDGE_H
#define INGRKNOWLEDGE_H
#include <iostream>

struct IngrKnowledge {
    bool knowRawHealing;
	bool knowStirredHealing;
    bool knowCookedHealing;
	bool knowRuinedHealing;
    bool knowNumMixes;
    bool knowCookTime;

    IngrKnowledge()
        : knowRawHealing(false), knowStirredHealing(false), knowCookedHealing(false), knowRuinedHealing(false), knowNumMixes(false),
		knowCookTime(false) {}

	IngrKnowledge(bool knowRawHealing, bool knowStirredHealing, bool knowCookedHealing, bool knowRuinedHealing, bool knowNumMixes, bool knowCookTime)
		: knowRawHealing(knowRawHealing), knowStirredHealing(knowStirredHealing), knowCookedHealing(knowCookedHealing),
		knowRuinedHealing(knowRuinedHealing), knowNumMixes(knowNumMixes), knowCookTime(knowCookTime) {}

	bool getKnowRawHealing() {
		return knowRawHealing;
	}

	bool getKnowStirredHealing() {
		return knowStirredHealing;
	}

	bool getKnowCookedHealing() {
		return knowCookedHealing;
	}

	bool getKnowRuinedHealing() {
		return knowRuinedHealing;
	}

	bool getKnowNumMixes() {
		return knowNumMixes;
	}

	bool getKnowCookTime() {
		return knowCookTime;
	}

	void printKnowledge() {
		std::cout << "Knows raw healing: " << knowRawHealing << std::endl;
		std::cout << "Knows stirred healing: " << knowStirredHealing << std::endl;
		std::cout << "Knows cooked healing: " << knowCookedHealing << std::endl;
		std::cout << "Knows ruined healing: " << knowRuinedHealing << std::endl;
		std::cout << "Knows number of mixes: " << knowNumMixes << std::endl;
		std::cout << "Knows cook time: " << knowCookTime << std::endl;
	}
};

#endif
