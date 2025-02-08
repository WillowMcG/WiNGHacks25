#ifndef INGRKNOWLEDGE_H
#define INGRKNOWLEDGE_H

struct IngrKnowledge {
    bool knowRawDamage;
    bool knowRawHealing;
    bool knowCookedDamage;
    bool knowCookedHealing;
    bool knowNumMixes;
    bool knowCookTime;

    IngrKnowledge()
        : knowRawDamage(false), knowRawHealing(false), knowCookedDamage(false),
        knowCookedHealing(false), knowNumMixes(false), knowCookTime(false) {}

    IngrKnowledge(bool rawDamage, bool rawHealing, bool cookedDamage, bool cookedHealing,
        bool numMixes, bool cookTime)
        : knowRawDamage(rawDamage), knowRawHealing(rawHealing), knowCookedDamage(cookedDamage),
        knowCookedHealing(cookedHealing), knowNumMixes(numMixes), knowCookTime(cookTime) {}
};

#endif
