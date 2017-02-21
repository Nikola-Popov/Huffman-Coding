#include "Commons.h"

namespace utility {
	void initializeCharacterVector(std::vector<uchar>& characters) {
		for(int i = 0; i < MAX_CHARACTERS_COUNT; i++) {
			characters[i] = i;
		}
	}

	std::vector<bool> eraseFirst(std::vector<bool> vector) {
		std::vector<bool> result;
		size_t size = vector.size();
		for(size_t i = 1; i < size; i++) {
			result.push_back(vector[i]);
		}
		return result;
	}

	size_t getAllNonZeroFrequenciesCount(std::vector<ulong>& vector) {
		size_t count = 0;
		size_t vectorSize = vector.size();
		for(int i = 0; i < vectorSize; i++) {
			if(vector[i] != 0) {
				count++;
			}
		}
		return count;
	}
}