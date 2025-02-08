#ifndef INGRPROPERTIES_H
#define INGRPROPERTIES_H

struct IngrProperties {
	int rawHealing;
	int cookedHealing;
	int numStirs;
	int cookTime;

	IngrProperties()
		: rawHealing(0), cookedHealing(0), numStirs(0), cookTime(0) {}

	IngrProperties(int rawHealing, int cookedHealing, int numStirs, int cookTime)
		: rawHealing(rawHealing), cookedHealing(cookedHealing),
		numStirs(numStirs), cookTime(cookTime) {}
};

#endif