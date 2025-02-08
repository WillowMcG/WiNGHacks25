#ifndef INGRSTATUS_H
#define INGRSTATUS_H

struct IngrStatus {
	bool isStirred;
	bool isCooked;
	bool isRuined;

public:
	IngrStatus()
		: isStirred(false), isCooked(false), isRuined(false) {}

	IngrStatus(bool isStirred, bool isCooked, bool isRuined)
		: isStirred(isStirred), isCooked(isCooked), isRuined(isRuined) {}
};

#endif
