#include "Item.h"

Item::Item() {
	index = 0;
	name = "";
	sprite = sf::Sprite();
	quantity = 0;
	gift_lvl = std::map <std::string, int>();
	properties = std::map <std::string, int>();
	notes = std::vector<std::string>();
}

Item::Item(int index, std::string name, sf::Sprite sprite, int quantity, std::map <std::string, int> gift_lvl, std::map <std::string, int> properties, std::vector<std::string> notes) {
	this->index = index;
	this->name = name;
	this->sprite = sprite;
	this->quantity = quantity;
	this->gift_lvl = gift_lvl;
	this->properties = properties;
	this->notes = notes;
}