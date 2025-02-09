#ifndef INGRSTATUS_H
#define INGRSTATUS_H

struct IngrStatus {
	bool isStirred;
	bool isCooked;
	bool isRuined;
	int timesStirred;
	int timeCooked;

public:
	IngrStatus()
		: isStirred(false), isCooked(false), isRuined(false), timesStirred(0), timeCooked(0) {}

	IngrStatus(bool isStirred, bool isCooked, bool isRuined, int numMixes, int timeCooked)
		: isStirred(isStirred), isCooked(isCooked), isRuined(isRuined), timesStirred(numMixes), timeCooked(timeCooked) {}
};

#endif