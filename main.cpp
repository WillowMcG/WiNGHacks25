//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "StatsManager.h"
#include "InventoryManager.h"
#include "Item.h"
#include "Ingredient.h"
#include "IngrGiftRatings.h"
#include "IngrProperties.h"
#include "IngrKnowledge.h"
#include "IngrStatus.h"
#include "Potion.h"
#include "Cooking.h"

// Test function
void initializeItems(InventoryManager& inventory_manager) {
	sf::Texture texture;
	texture.loadFromFile("Cauldron_Icon copy.png");
	sf::Sprite sprite(texture);

	std::shared_ptr<Item> item = std::make_shared<Item>(0, "Cauldron", sprite, 1);
	inventory_manager.items.push_back(item);

	IngrGiftRatings gift_ratings({ 1, 1, 1 });
	IngrProperties properties(1, 1, 1, 1, 1, 1);
	IngrKnowledge knowledge(true, false, false, false, false, false);
	IngrStatus status(false, false, false);
	std::shared_ptr<Item> ingredient = std::make_shared<Ingredient>(1, "Mandrake Root", sprite, 1, properties, knowledge, gift_ratings, status);
	inventory_manager.items.push_back(ingredient);

	IngrGiftRatings gift_ratings2({ -5, 11, 0 });
	IngrProperties properties2(7, 3, -2, -20, 5, 20);
	IngrKnowledge knowledge2(true, true, true, true, true, true);
	IngrStatus status2(true, true, true);
	std::shared_ptr<Item> ingredient2 = std::make_shared<Ingredient>(2, "Dragon Scale", sprite, 1, properties2, knowledge2, gift_ratings2, status2);
	inventory_manager.items.push_back(ingredient2);

	std::unordered_map<std::string, int> ingredients = { { "Mandrake Root", 1 }, { "Dragon Scale", 1 } };
	std::shared_ptr<Item> potion = std::make_shared<Potion>(3, "Potion of Strength", sprite, 1, properties2, knowledge2, gift_ratings2, status2, ingredients, true, true);
	inventory_manager.items.push_back(potion);
}

void initializeDebug(InventoryManager& inventory_manager) {
	sf::Texture texture;
	texture.loadFromFile("Cauldron_Icon copy.png");
	sf::Sprite sprite(texture);

	std::shared_ptr<Item> item = std::make_shared<Item>(0, "Egg", sprite, 1);
	inventory_manager.items.push_back(item);
	for (int i = 0; i < inventory_manager.items.size(); i++) {
		std::cout << inventory_manager.items[i]->name << std::endl;
	}
}

void eating(InventoryManager& inventory_manager, StatsManager& stats_manager, std::string name) {
	auto item = inventory_manager.getItemPtr(name);
	auto ingredient = std::dynamic_pointer_cast<Ingredient>(item);
	auto potion = std::dynamic_pointer_cast<Potion>(item);
	int healAmount = 0;
	if (ingredient) {
		if (ingredient->getIngrStatus().isCooked) {
			healAmount = ingredient->getIngrProperties().cookedHealing;
		}
		else if (ingredient->getIngrStatus().isStirred) {
			healAmount = ingredient->getIngrProperties().stirredHealing;
		}
		else {
			healAmount = ingredient->getIngrProperties().rawHealing;
		}
		stats_manager.changeHealth(healAmount);
	}
	else {
		std::cout << "Item is not an ingredient." << std::endl;
	}
}

int main() {

	InventoryManager debug_inventory;
	initializeDebug(debug_inventory);

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

	auto potion = std::dynamic_pointer_cast<Potion>(inventory_manager.getItemPtr(3));
	if (potion) {
		potion->getIngrProperties().printProperties();
		std::unordered_map<std::string, int> ingredients = potion->getIngredients();
		for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
			std::cout << it->first << ": " << it->second << std::endl;
		}
	}
	else {
		std::cout << "Item is not a potion." << std::endl;
	}

	std::cout << "Before eating: " << stats_manager.getHealth() << std::endl;

	eating(inventory_manager, stats_manager, "Mandrake Root");
	std::cout << "After eating: " << stats_manager.getHealth() << std::endl;

	eating(inventory_manager, stats_manager, "Potion of Strength");
	std::cout << "After drinking: " << stats_manager.getHealth() << std::endl;

	std::cout << "Egg is in debug: " << debug_inventory.inInventory(debug_inventory.getItem("Egg")) << std::endl;
	for (int i = 0; i < debug_inventory.items.size(); i++) {
		std::cout << debug_inventory.items[i]->name << std::endl;
	}

	std::cout << "In inventory:" <<
		inventory_manager.inInventory(debug_inventory.getItem("Egg")) << std::endl;
	for (int i = 0; i < inventory_manager.items.size(); i++) {
		std::cout << inventory_manager.items[i]->name << std::endl;
	}

	inventory_manager.pickUpItem(debug_inventory.getItemPtr("Egg"));
	std::cout << "In inventory:" <<
		inventory_manager.inInventory(debug_inventory.getItem("Egg")) << std::endl;
	for (int i = 0; i < inventory_manager.items.size(); i++) {
		std::cout << inventory_manager.items[i]->name << std::endl;
	}

	std::cout << "Egg quantity: " << inventory_manager.getItemPtr("Egg")->quantity << std::endl;
	inventory_manager.pickUpItem(debug_inventory.getItemPtr("Egg"));
	std::cout << "Newer Egg quantity: " << inventory_manager.getItemPtr("Egg")->quantity << std::endl;
	inventory_manager.pickUpItem(debug_inventory.getItemPtr("Egg"), 10);
	std::cout << "Even newer Egg quantity: " << inventory_manager.getItemPtr("Egg")->quantity << std::endl;

	return 0;
}