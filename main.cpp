//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "StatsManager.h"
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

	std::shared_ptr<Item> item = std::make_shared<Item>(0, "Cauldron", sprite, 1);
	inventory_manager.items.push_back(item);

	IngrGiftRating gift_rating({ 1, 1, 1 });
	IngrProperties properties(1, 1, 1, 1, 1, 1);
	IngrKnowledge knowledge(true, false, false, false, false, false);
	std::shared_ptr<Item> ingredient = std::make_shared<Ingredient>(1, "Mandrake Root", sprite, 1, properties, knowledge, gift_rating);
	inventory_manager.items.push_back(ingredient);
}

int main() {

	StatsManager stats_manager;
	std::cout << stats_manager.getHealth() << std::endl;
	stats_manager.printRelationshipLvls();

	
	InventoryManager inventory_manager;
	initializeItems(inventory_manager);
	for (int i = 0; i < inventory_manager.items.size(); i++) {
		std::cout << inventory_manager.items[i]->name << std::endl;
	}
	
	auto item = inventory_manager.getItemPtr(1);

	auto ingredient = std::dynamic_pointer_cast<Ingredient>(item);
	if (ingredient) {
		ingredient->getIngrKnowledge().printKnowledge();
	}
	else {
		std::cout << "Item is not an ingredient." << std::endl;
	}

	return 0;
}