//
// Created by Jules on 2/7/2025.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "InventoryManager.h"
#include "Item.h"

void initializeItems(InventoryManager& inventory_manager) {
	sf::Texture texture;
	texture.loadFromFile("Cauldron_Icon copy.png");
	sf::Sprite sprite(texture);
	std::map <std::string, int> gift_lvl;
	std::map <std::string, int> properties;
	std::vector<std::string> notes;
	Item item(0, "Cauldron", sprite, 1, gift_lvl, properties, notes);
	inventory_manager.items.push_back(item);
}

int main() {
	
	InventoryManager inventory_manager;
	initializeItems(inventory_manager);
	for (int i = 0; i < inventory_manager.items.size(); i++) {
		std::cout << inventory_manager.items[i].name << std::endl;
	}
    return 0;
}