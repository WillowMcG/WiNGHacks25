#pragma once
#include "RelationshipLvls.h"

class StatsManager{
	int health;
	int hunger;
	RelationshipLvls relationshipLvls;
public:
	StatsManager();
	~StatsManager();
	int getHealth();
	int getHunger();
	void setHealth(int health);
	void setHunger(int hunger);
	void increaseHealth(int health);
	void increaseHunger(int hunger);
	void decreaseHealth(int health);
	void decreaseHunger(int hunger);
	int getRelationshipLvl(std::string name);
	RelationshipLvls& getRelationshipLvls();
	void setRelationshipLvl(std::string name, int value);
	void setRelationshipLvls(int value);
	void increaseRelationshipLvl(std::string name);
	void increaseRelationshipLvl(std::string name, int value);
	void decreaseRelationshipLvl(std::string name);
	void decreaseRelationshipLvl(std::string name, int value);
	void resetRelationshipLvl(std::string name);
	void resetRelationshipLvls();
	void printRelationshipLvl(std::string name);
	void printRelationshipLvls();
};

