#ifndef INGRPROPERTIES_H
#define INGRPROPERTIES_H

#include <iostream>

struct IngrProperties {
	int rawHealing;
	int stirredHealing;
	int cookedHealing;
	int ruinedHealing;
	int numStirs;
	int cookTime;

	IngrProperties()
		: rawHealing(0), stirredHealing(0), cookedHealing(0), ruinedHealing(0), numStirs(0), cookTime(0) {}

	IngrProperties(int rawHealing, int stirredHealing, int cookedHealing, int ruinedHealing, int numStirs, int cookTime)
		: rawHealing(rawHealing), stirredHealing(stirredHealing), cookedHealing(cookedHealing), ruinedHealing(ruinedHealing), numStirs(numStirs),
		cookTime(cookTime) {}

	void printProperties() const {
		std::cout << "Raw Healing: " << rawHealing << std::endl;
		std::cout << "Stirred Healing: " << stirredHealing << std::endl;
		std::cout << "Cooked Healing: " << cookedHealing << std::endl;
		std::cout << "Ruined Healing: " << ruinedHealing << std::endl;
		std::cout << "Number of Stirs: " << numStirs << std::endl;
		std::cout << "Cook Time: " << cookTime << std::endl;
	}
};

#endif