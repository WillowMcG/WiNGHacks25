#pragma once
#include <SFML/Graphics.hpp>


class Item {
public:
	int index;
	std::string name;
	sf::Sprite sprite;
	int quantity;
	std::map <std::string, int> gift_lvl;
	std::map <std::string, int> properties;
	std::vector<std::string> notes;

	Item();
	Item(int index, std::string name, sf::Sprite sprite, int quantity, std::map <std::string, int> gift_lvl, std::map <std::string, int> properties, std::vector<std::string> notes);
};

