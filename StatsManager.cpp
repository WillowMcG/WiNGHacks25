#include "StatsManager.h"

StatsManager::StatsManager() {
	health = 100;
	hunger = 100;
}

StatsManager::~StatsManager() {
}

int StatsManager::getHealth() {
	return health;
}

int StatsManager::getHunger() {
	return hunger;
}

void StatsManager::setHealth(int health) {
	this->health = health;
}

void StatsManager::setHunger(int hunger) {
	this->hunger = hunger;
}

void StatsManager::increaseHealth(int health) {
	this->health += health;
}

void StatsManager::increaseHunger(int hunger) {
	this->hunger += hunger;
}

void StatsManager::decreaseHealth(int health) {
	this->health -= health;
}

void StatsManager::decreaseHunger(int hunger) {
	this->hunger -= hunger;
}

int StatsManager::getRelationshipLvl(std::string name) {
	return relationshipLvls.getLvl(name);
}

RelationshipLvls& StatsManager::getRelationshipLvls() {
	return relationshipLvls;
}

void StatsManager::setRelationshipLvl(std::string name, int value) {
	relationshipLvls.setLvl(name, value);
}

void StatsManager::setRelationshipLvls(int value) {
	relationshipLvls = RelationshipLvls(std::vector<int>(3, value));
}

void StatsManager::increaseRelationshipLvl(std::string name) {
	relationshipLvls.increaseLvl(name);
}

void StatsManager::increaseRelationshipLvl(std::string name, int value) {
	relationshipLvls.increaseLvl(name, value);
}

void StatsManager::decreaseRelationshipLvl(std::string name) {
	relationshipLvls.decreaseLvl(name);
}

void StatsManager::decreaseRelationshipLvl(std::string name, int value) {
	relationshipLvls.decreaseLvl(name, value);
}

void StatsManager::resetRelationshipLvl(std::string name) {
	relationshipLvls.resetLvl(name);
}

void StatsManager::resetRelationshipLvls() {
	relationshipLvls.resetAllLvls();
}

void StatsManager::printRelationshipLvl(std::string name) {
	std::cout << name << ": " << relationshipLvls.getLvl(name) << std::endl;
}

void StatsManager::printRelationshipLvls() {
	relationshipLvls.printAllLvls();
}