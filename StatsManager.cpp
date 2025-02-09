#include "StatsManager.h"

StatsManager::StatsManager() {
	health = 100;
	hunger = 50;
}

StatsManager::~StatsManager() {
}

// Health functions
int StatsManager::getHealth() const {
	return health;
}

void StatsManager::setHealth(int health) {
	if (health < 0 || health > 100) {
		return;
	}
	this->health = health;
}

void StatsManager::increaseHealth() {
	health++;
	if (health > 100) {
		health = 100;
	}
}

void StatsManager::decreaseHealth() {
	health--;
	if (health < 0) {
		health = 0;
	}
}

void StatsManager::changeHealth(int val) {
	health += val;
	if (health > 100) {
		health = 100;
	}
	else if (health < 0) {
		health = 0;
	}
}

void StatsManager::resetHealth() {
	health = 100;
}

// Hunger functions
int StatsManager::getHunger() const {
	return hunger;
}

void StatsManager::setHunger(int hunger) {
	if (hunger < 0 || hunger > 100) {
		return;
	}
	this->hunger = hunger;
}

void StatsManager::increaseHunger() {
	hunger++;
	if (hunger > 100) {
		hunger = 100;
	}
}

void StatsManager::decreaseHunger() {
	hunger--;
	if (hunger < 0) {
		hunger = 0;
	}
}

void StatsManager::changeHunger(int val) {
	hunger += val;
	if (hunger > 100) {
		hunger = 100;
	}
	else if (hunger < 0) {
		hunger = 0;
	}
}

void StatsManager::resetHunger() {
	hunger = 50;
}

// Relationship functions
int StatsManager::getRelationshipLvl(std::string name) {
	return relationshipLvls.lvls[name];
}

const RelationshipLvls& StatsManager::getRelationshipLvls() const {
	return relationshipLvls;
}

void StatsManager::setRelationshipLvl(std::string name, int val) {
	if (val < 0 || val > 100) {
		return;
	}
	relationshipLvls.lvls[name] = val;
}

void StatsManager::setRelationshipLvls(int val) {
	if (val < 0 || val > 100) {
		return;
	}
	for (auto& pair : relationshipLvls.lvls) {
		pair.second = val;
	}
}

void StatsManager::increaseRelationshipLvl(std::string name) {
	relationshipLvls.lvls[name]++;
	if (relationshipLvls.lvls[name] > 100) {
		relationshipLvls.lvls[name] = 100;
	}
}

void StatsManager::increaseRelationshipLvls() {
	for (auto& pair : relationshipLvls.lvls) {
		pair.second++;
		if (pair.second > 100) {
			pair.second = 100;
		}
	}
}

void StatsManager::decreaseRelationshipLvl(std::string name) {
	relationshipLvls.lvls[name]--;
	if (relationshipLvls.lvls[name] < 0) {
		relationshipLvls.lvls[name] = 0;
	}
}

void StatsManager::decreaseRelationshipLvls() {
	for (auto& pair : relationshipLvls.lvls) {
		pair.second--;
		if (pair.second < 0) {
			pair.second = 0;
		}
	}
}

void StatsManager::changeRelationshipLvl(std::string name, int val) {
	if (val < 0 || val > 100) {
		return;
	}
	relationshipLvls.lvls[name] += val;
}

void StatsManager::changeRelationshipLvls(int lvl) {
	if (lvl < 0 || lvl > 100) {
		return;
	}
	for (auto& pair : relationshipLvls.lvls) {
		pair.second += lvl;
	}
}

void StatsManager::resetRelationshipLvl(std::string name) {
	relationshipLvls.lvls[name] = 0;
}

void StatsManager::resetRelationshipLvls() {
	for (auto& pair : relationshipLvls.lvls) {
		pair.second = 0;
	}
}

void StatsManager::printRelationshipLvl(std::string name) {
	std::cout << name << ": " << relationshipLvls.lvls[name] << std::endl;
}

void StatsManager::printRelationshipLvls() {
	for (auto& pair : relationshipLvls.lvls) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
}