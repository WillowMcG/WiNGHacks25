#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Item.h"

class InventoryManager {
public:
	std::vector<Item> items;
	
	InventoryManager();
	bool inInventory(std::string name);
	Item getItem(int index);
	Item getItem(std::string name);
	Item& getItemRef(int index);
	Item& getItemRef(std::string name);
	void print();
	void pickUpItem(Item item);
	void pickUpItem(Item item, int quantity);
	void discardItem(Item item);
	void discardItem(Item item, int quantity);
	void tradeItem(Item item, int quantity, std::string traderName);
	void tradeItem(Item given_item, int givenQuantity, std::string traderName, Item recievedItem, int recievedQuantity);
	//void drawInventory(sf::RenderWindow& window, int width, int height, int visible_items);
	//void drawCookingInventory(sf::RenderWindow& window, int width, int height, int visible_items);
};