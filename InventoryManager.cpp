#include <iostream>

#include "InventoryManager.h"

InventoryManager::InventoryManager() {
	items = std::vector<Item>();
}

bool InventoryManager::inInventory(Item item) {
	for (const auto& invItem : items) {
		if (invItem.name == item.name) {
			return true;
		}
	}
	return false;
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

void InventoryManager::pickUpItem(Item item) {
	for (auto& inventoryItem : items) {
		if (inventoryItem.name == item.name) {
			inventoryItem.quantity++;
			return;
		}
	}

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





