#pragma once
#include <SFML/Graphics.hpp>
#include "Item.h"

class InventoryManager {
	std::vector<Item> items;
public:
	InventoryManager();
	void pickUpItem(Item item);
	void pickUpItem(Item item, int quantity);
	void discardItem(Item item);
	void discardItem(Item item, int quantity);
	void tradeItem(Item item, int quantity, std::string trader_name);
	void tradeItem(Item given_item, int given_quantity, std::string trader_name, Item recieved_item, int recieved_quantity);
	void drawInventory(sf::RenderWindow& window, int width, int height, int visible_items);
	void drawCookingInventory(sf::RenderWindow& window, int width, int height, int visible_items);
};