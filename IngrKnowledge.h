#ifndef INGRKNOWLEDGE_H
#define INGRKNOWLEDGE_H
#include <iostream>

struct IngrKnowledge {
	bool knowRawHealing;
	bool knowStirredHealing;
	bool knowCookedHealing;
	bool knowRuinedHealing;
  bool knowNumStirs;
  bool knowCookTime;

  IngrKnowledge()
        : knowRawHealing(false), knowStirredHealing(false), knowCookedHealing(false), knowRuinedHealing(false), knowNumStirs(false),
	knowCookTime(false) {}

	IngrKnowledge(bool knowRawHealing, bool knowStirredHealing, bool knowCookedHealing, bool knowRuinedHealing, bool knowNumMixes, bool knowCookTime)
		: knowRawHealing(knowRawHealing), knowStirredHealing(knowStirredHealing), knowCookedHealing(knowCookedHealing),
		knowRuinedHealing(knowRuinedHealing), knowNumStirs(knowNumStirs), knowCookTime(knowCookTime) {}
};

#endif