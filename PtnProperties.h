#ifndef PTNPROPERTIES_H
#define PTNPROPERTIES_H

#include <iostream>
#include <unordered_map>

struct PtnProperties {
	int rawHealing;
	int cookedHealing;
	int numStirs;
	int cookTime;

	PtnProperties()
		: rawHealing(0), cookedHealing(0), numStirs(0), cookTime(0) {}

	PtnProperties(int rawHealing, int cookedHealing, int numStirs, int cookTime)
		: rawHealing(rawHealing), cookedHealing(cookedHealing),
		numStirs(numStirs), cookTime(cookTime) {}

	void printProperties() {
		std::cout << "Raw healing: " << rawHealing << std::endl;
		std::cout << "Cooked healing: " << cookedHealing << std::endl;
		std::cout << "Number of stirs: " << numStirs << std::endl;
		std::cout << "Cook time: " << cookTime << std::endl;
	}
};

#endif