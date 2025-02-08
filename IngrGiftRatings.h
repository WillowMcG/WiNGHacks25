#ifndef INGRGIFTRATINGS_H
#define INGRGIFTRATINGS_H

#include <unordered_map>
#include <string>

struct IngrGiftRatings {
    std::unordered_map<std::string, int> ratings;

	IngrGiftRatings()
	{
		ratings["character_a"] = 0;
		ratings["character_b"] = 0;
		ratings["character_c"] = 0;
	}

	IngrGiftRatings(std::vector<int> vec) {
		for (int i = 0; i < vec.size(); i++) {
			if (i >= 3) {
				break;
			}
			ratings["character_" + std::to_string(i)] = vec[i];
		}

	}
};

#endif