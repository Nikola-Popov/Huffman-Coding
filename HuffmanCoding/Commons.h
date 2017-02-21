#ifndef _COMMONS_H_
#define _COMMONS_H_

#include <vector>

typedef unsigned char uchar;
typedef unsigned long ulong;

#define TASK_COMPLETE_NOTIFIER std::cout << "\t|-> COMPLETE." << std::endl;
#define TASK_READING_NOTIFIER std::cout << "[>] Reading data ... " << std::endl;
#define TASK_PACKING_NOTIFIER std::cout << "[>] Packing data ... " << std::endl;
#define TASK_UNPACKING_NOTIFIER std::cout << "[>] Unpacking data ... " << std::endl;

const size_t MAX_CHARACTERS_COUNT = 256;
const size_t MAX_ARGUMENTS_COUNT = 4;

namespace utility {
	void initializeCharacterVector(std::vector<uchar>& characters);
	std::vector<bool> eraseFirst(std::vector<bool> vector);
	size_t getAllNonZeroFrequenciesCount(std::vector<ulong>& vector);
}

#endif //_COMMONS_H_




