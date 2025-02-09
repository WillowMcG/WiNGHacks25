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
};

#endif