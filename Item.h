#pragma once
#include <SFML/Graphics.hpp>

class Item {
public:
	int index;
	std::string name;
	sf::Sprite sprite;
	int quantity;

	Item();
	Item(int index, std::string name, sf::Sprite sprite, int quantity);
	virtual ~Item();

	int getIndex() const;
	std::string getName() const;
	sf::Sprite getSprite() const;
	int getQuantity() const;
};

