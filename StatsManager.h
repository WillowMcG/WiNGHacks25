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
	void setHealth(int health);
	void increaseHealth();
	void decreaseHealth();
	void changeHealth(int val);
	void resetHealth();

	int getHunger();
	void setHunger(int hunger);
	void increaseHunger();
	void decreaseHunger();
	void changeHunger(int val);
	void resetHunger();

	int getRelationshipLvl(std::string name);
	RelationshipLvls& getRelationshipLvls();
	void setRelationshipLvl(std::string name, int val);
	void setRelationshipLvls(int lvl);
	void increaseRelationshipLvl(std::string name);
	void increaseRelationshipLvls();
	void decreaseRelationshipLvl(std::string name);
	void decreaseRelationshipLvls();
	void changeRelationshipLvl(std::string name, int val);
	void changeRelationshipLvls(int lvl);
	void resetRelationshipLvl(std::string name);
	void resetRelationshipLvls();
	void printRelationshipLvl(std::string name);
	void printRelationshipLvls();
};

