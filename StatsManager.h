#pragma once
#include "RelationshipLvls.h"

class StatsManager{
	int health;
	int hunger;
	RelationshipLvls relationshipLvls;
public:
	StatsManager();
	~StatsManager();

	int getHealth() const;
	void setHealth(int health);
	void increaseHealth();
	void decreaseHealth();
	void changeHealth(int val);
	void resetHealth();

	int getHunger() const;
	void setHunger(int hunger);
	void increaseHunger();
	void decreaseHunger();
	void changeHunger(int val);
	void resetHunger();

	int getRelationshipLvl(std::string name);
	const RelationshipLvls& getRelationshipLvls() const;
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

