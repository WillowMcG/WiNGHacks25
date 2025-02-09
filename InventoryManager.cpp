#include <iostream>

#include "InventoryManager.h"

InventoryManager::InventoryManager() {
	items = std::vector<Item>();
}

bool InventoryManager::inInventory(std::string name) {
	for (const auto& invItem : items) {
		if (invItem.name == name) {
			return true;
		}
	}
	return false;
}

void InventoryManager::print() {
	for (auto it : items) {
		std::cout << it.name << std::endl;
		std::cout << it.quantity << std::endl;
	}
}

Item InventoryManager::getItem(int index) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].index == index) {
			return items[i];
		}
	}
	return Item();
}

Item InventoryManager::getItem(std::string name) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == name) {
			return items[i];
		}
	}
	return Item();
}

int InventoryManager::getNumItems() {
	return items.size();
}


void InventoryManager::pickUpItem(Item item) {
	for (auto& inventoryItem : items) {
		if (inventoryItem.name == item.name) {
			std::cout << "Picked up another item " << item.name << std::endl;
			inventoryItem.quantity++;
			return;
		}
	}
	std::cout << "Picked up new item " << item.name << std::endl;
	items.push_back(item);
}

void InventoryManager::pickUpItem(Item item, int quantity) {

	for (auto& inventoryItem : items) {
		if (inventoryItem.name == item.name) {
			inventoryItem.quantity += quantity;
			return;
		}
	}

	item.quantity = quantity;
	items.push_back(item);
}

void InventoryManager::discardItem(Item item) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].index == item.index) {
			items.erase(items.begin() + i);
			break;
		}
	}
}

void InventoryManager::discardItem(Item item, int quantity) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].index == item.index) {
			items[i].quantity -= quantity;
			if (items[i].quantity <= 0) {
				items.erase(items.begin() + i);
			}
			break;
		}
	}
}

void InventoryManager::tradeItem(Item item, int quantity, std::string traderName) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].index == item.index) {
			items[i].quantity -= quantity;
			if (items[i].quantity <= 0) {
				items.erase(items.begin() + i);
			}
			break;
		}
	}
}

void InventoryManager::tradeItem(Item givenItem, int givenQuantity, std::string traderName, Item recievedItem, int recievedQuantity) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].index == givenItem.index) {
			items[i].quantity -= givenQuantity;
			if (items[i].quantity <= 0) {
				items.erase(items.begin() + i);
			}
			break;
		}
	}
	recievedItem.quantity = recievedQuantity;
	items.push_back(Item(recievedItem));
}

void InventoryManager::drawInventory(sf::RenderWindow &window, sf::Font& body, int width, int height, Textures& textures) {
	sf::Sprite inventoryBackground(textures.getBackgroundTextures().at(4));
	inventoryBackground.setOrigin(width/2, height/2);
	inventoryBackground.setPosition(width/2, height/2);

	window.draw(inventoryBackground);

	int hindex = 0;
	int vindex = 0;
	for (auto it : items) {
		if (it.name == "Cauldron") {
			it.sprite.setTexture(textures.getItemTextures().at(0));
			it.sprite.setScale(.75, .75);
		} else if (it.name == "Djorchertwitz") {
			it.sprite.setTexture(textures.getPlantTextures().at(0));
			it.sprite.setScale(1.5, 1.5);
		} else if (it.name == "Hygogix") {
			it.sprite.setTexture(textures.getPlantTextures().at(1));
			it.sprite.setScale(1.5, 1.5);
		} else if (it.name == "Spindlewort") {
			it.sprite.setTexture(textures.getPlantTextures().at(2));
			it.sprite.setScale(1.5,1.5);
		}
		hindex++;
		if (hindex == 5) {
			hindex = 0;
			vindex++;
		}

		it.sprite.setPosition(200+266*hindex, 80+256*vindex);
		window.draw(it.sprite);
	}
}






