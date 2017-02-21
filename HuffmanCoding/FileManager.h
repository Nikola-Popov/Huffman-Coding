#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "HuffmanTree.h"
#include <fstream>
#include <vector>


class FileManager {
public:
	static void pack(const std::string sourceFilename, const std::string destinationFilename);
	static void unpack(const std::string sourceFilename, const std::string destinationFilename);
private:
	static HuffmanTree deserializeTreeFromFile(std::ifstream& inputStream);
	static HuffmanTree parseFileDataIntoTree(std::ifstream& inputStream);
	static void serializeTreeToFile(HuffmanTree& huffmanTree, std::ofstream& outputStream);
	static size_t getFileSize(std::ifstream& inputStream);
};

#endif //_FILE_MANAGER_H_