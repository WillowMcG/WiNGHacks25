#ifndef RELATIONSHIPLVLS_H
#define RELATIONSHIPLVLS_H

#include <iostream>
#include <unordered_map>
#include <string>

struct RelationshipLvls {
	std::unordered_map<std::string, int> lvls;

	RelationshipLvls()
	{
		lvls["character_a"] = 0;
		lvls["character_b"] = 0;
		lvls["character_c"] = 0;
	}

	RelationshipLvls(std::vector<int> vec) {
		for (int i = 0; i < vec.size(); i++) {
			if (i >= 3) {
				break;
			}
			lvls["character_" + std::to_string(i)] = vec[i];
		}

	}

	int getLvl(std::string character) {
		return lvls[character];
	}

	void setLvl(std::string character, int lvl) {
		lvls[character] = lvl;
	}

	void increaseLvl(std::string character) {
		lvls[character]++;
	}

	void increaseLvl(std::string character, int amount) {
		lvls[character] += amount;
	}

	void decreaseLvl(std::string character) {
		lvls[character]--;
	}

	void decreaseLvl(std::string character, int amount) {
		lvls[character] -= amount;
	}

	void resetLvl(std::string character) {
		lvls[character] = 0;
	}

	void resetAllLvls() {
		for (auto& pair : lvls) {
			pair.second = 0;
		}
	}

	void printAllLvls() {
		for (auto& pair : lvls) {
			std::cout << pair.first << " lvl: " << pair.second << std::endl;
		}
	}
};

#endif