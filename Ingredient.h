#ifndef INGRINGREDIENT_H
#define INGRINGREDIENT_H

#include "Item.h"
#include "IngrGiftRating.h"
#include "IngrProperties.h"
#include "IngrKnowledge.h"

class Ingredient : public Item {
public:
    IngrGiftRating ingrGiftRating;
    IngrProperties ingrProperties;
    IngrKnowledge ingrKnowledge;

    Ingredient(int index, std::string name, sf::Sprite sprite, int quantity,
        const IngrGiftRating& giftRating, const IngrProperties& properties, const IngrKnowledge& ingrKnowledge);
};

#endif