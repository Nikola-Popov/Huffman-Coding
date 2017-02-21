#include <iostream>
#include <vector>
#include <fstream>
#include "MinHeap.h"
#include "HuffmanTree.h"
#include "GeneratedPair.h"
#include "Commons.h"
#include "FileManager.h"
#include <string.h>

int main(int argc,char* argv[]) {
	if(argc < MAX_ARGUMENTS_COUNT || argc > MAX_ARGUMENTS_COUNT) {
		return -1;
	}
	if(strcmp(argv[1], "-Pack") == 0) {
		FileManager::pack(argv[2], argv[3]);
	} else if(strcmp(argv[1], "-Unpack") == 0) {
		FileManager::unpack(argv[2], argv[3]);
	} else {
		std::cout << "Invalid command!" << std::endl;
		return -1;
	}
	system("pause");
	return 0;
}