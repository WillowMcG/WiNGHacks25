#ifndef INGRPROPERTIES_H
#define INGRPROPERTIES_H

struct IngrProperties {
	int rawDamage;
	int rawHealing;
	int cookedDamage;
	int cookedHealing;
	int numStirs;
	int cookTime;

	IngrProperties()
		: rawDamage(0), rawHealing(0), cookedDamage(0), cookedHealing(0), numStirs(0), cookTime(0) {}

	IngrProperties(int rawDamage, int rawHealing, int cookedDamage, int cookedHealing, int numStirs, int cookTime)
		: rawDamage(rawDamage), rawHealing(rawHealing), cookedDamage(cookedDamage), cookedHealing(cookedHealing),
		numStirs(numStirs), cookTime(cookTime) {}
};

#endif