#include "Item.h"

Item::Item() {
	index = 0;
	name = "";
	sprite = sf::Sprite();
	quantity = 0;
}

Item::Item(int index, std::string name, sf::Sprite sprite, int quantity) {
	this->index = index;
	this->name = name;
	this->sprite = sprite;
	this->quantity = quantity;
}

Item::~Item() {
}

int Item::getIndex() const {
	return index;
}

std::string Item::getName() const {
	return name;
}

sf::Sprite Item::getSprite() const {
	return sprite;
}

int Item::getQuantity() const {
	return quantity;
}