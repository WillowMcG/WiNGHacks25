//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "InventoryManager.h"
#include "Item.h"
#include "Ingredient.h"
#include "IngrGiftRating.h"
#include "IngrProperties.h"
#include "IngrKnowledge.h"

void initializeItems(InventoryManager& inventory_manager) {
	sf::Texture texture;
	texture.loadFromFile("Cauldron_Icon copy.png");
	sf::Sprite sprite(texture);
	Item item(0, "Cauldron", sprite, 1);
	inventory_manager.items.push_back(item);
	IngrGiftRating gift_rating({ 1, 1, 1 });
	IngrProperties properties(1, 1, 1, 1, 1, 1);
	IngrKnowledge knowledge(true, false, false, false, false, false);
	Ingredient ingredient(1, "Mandrake Root", sprite, 1, gift_rating, properties, knowledge);
	inventory_manager.items.push_back(ingredient);
}

int main() {
	
	InventoryManager inventory_manager;
	initializeItems(inventory_manager);
	for (int i = 0; i < inventory_manager.items.size(); i++) {
		std::cout << inventory_manager.items[i].name << std::endl;
	}
	return 0;
}