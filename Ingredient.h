#ifndef INGRINGREDIENT_H
#define INGRINGREDIENT_H

#include "Item.h"
#include "IngrProperties.h"
#include "IngrKnowledge.h"
#include "IngrGiftRating.h"

class Ingredient : public Item {
public:
    IngrProperties ingrProperties;
    IngrKnowledge ingrKnowledge;
    IngrGiftRating ingrGiftRating;

    Ingredient(int index, std::string name, sf::Sprite sprite, int quantity, const IngrProperties& properties, const IngrKnowledge& ingrKnowledge,
        const IngrGiftRating& giftRating);

    IngrProperties getIngrProperties() const;
    IngrKnowledge getIngrKnowledge() const;
	IngrGiftRating getIngrGiftRating() const;



};

#endif