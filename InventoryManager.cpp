#include "InventoryManager.h"

InventoryManager::InventoryManager() {
	items = std::vector<Item>();
}

void InventoryManager::pickUpItem(Item item) {
	items.push_back(item);
}

void InventoryManager::pickUpItem(Item item, int quantity) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].index == item.index) {
			items[i].quantity += quantity;
			return;
		}
	}
	items.push_back(item);
	items[items.size() - 1].quantity = quantity;
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

void InventoryManager::tradeItem(Item item, int quantity, std::string trader_name) {
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

void InventoryManager::tradeItem(Item given_item, int given_quantity, std::string trader_name, Item recieved_item, int recieved_quantity) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].index == given_item.index) {
			items[i].quantity -= given_quantity;
			if (items[i].quantity <= 0) {
				items.erase(items.begin() + i);
			}
			break;
		}
	}
	recieved_item.quantity = recieved_quantity;
	items.push_back(recieved_item);
}

