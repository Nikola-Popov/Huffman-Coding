#include "FileManager.h"
#include <string.h>
#include "GeneratedPair.h"
#include <iostream>

using namespace utility;

void FileManager::pack(const std::string sourceFilename, const std::string destinationFilename) {
	std::ifstream inputStream(sourceFilename, std::ios::binary);
	TASK_READING_NOTIFIER;
	HuffmanTree huffmanTree = parseFileDataIntoTree(inputStream);
	inputStream.seekg(0, std::ios::beg);
	if(huffmanTree.isEmpty()) {
		return;
	}
	std::ofstream outputStream(destinationFilename, std::ios::binary);
	serializeTreeToFile(huffmanTree, outputStream);
	std::vector<GeneratedPair> generatedPairs = huffmanTree.generateCodes();
	size_t generatedPairsSize = generatedPairs.size();
	TASK_COMPLETE_NOTIFIER;
	TASK_PACKING_NOTIFIER;
	if(outputStream && inputStream) {
		size_t fileSize = getFileSize(inputStream);
		uchar currentChar;
		std::vector<bool> code;
		size_t codeSize = 0;
		char tmpChar = 0;
		for(int i = 0; i < fileSize; i++) {
			inputStream.read((char*)&currentChar, sizeof(currentChar));
			for(int j = 0; j < generatedPairsSize; j++) {
				if(currentChar == generatedPairs[j].getCharacter()) {
					code = generatedPairs[j].getHuffmanCode();
					codeSize = code.size();
					outputStream.write((char*)&codeSize, sizeof(codeSize));
					for(int k = 0; k < codeSize; k++) {
						tmpChar = code[k];
						outputStream.write((char*)&tmpChar, sizeof(tmpChar));
					}
					break;
				}
			}
		}
	} else {
		throw "Error while packing the file!";
	}
	TASK_COMPLETE_NOTIFIER;
	outputStream.close();
	inputStream.close();
}

HuffmanTree FileManager::parseFileDataIntoTree(std::ifstream& inputStream) {
	std::vector<uchar> characters(MAX_CHARACTERS_COUNT);
	std::vector<ulong> frequencies(MAX_CHARACTERS_COUNT, 0);

	if(inputStream) {
		size_t fileSize = getFileSize(inputStream);
		if(fileSize == 0) {
			return HuffmanTree();
		}

		initializeCharacterVector(characters);
		uchar currentChar;
		for(int i = 0; i < fileSize; i++) {
			inputStream.read((char*)&currentChar, sizeof(currentChar));
			frequencies[currentChar]++;
		}
	} else {
		throw "Error while parsing the data from a file!";
	}
	return HuffmanTree(characters, frequencies);
}

size_t FileManager::getFileSize(std::ifstream& inputStream) {
	size_t size = 0;
	if(inputStream) {
		inputStream.seekg(0, std::ios::end);
		size = inputStream.tellg();
		inputStream.seekg(0, std::ios::beg);
	} else {
		throw "Error while getting file size!";
	}
	return size;
}

void FileManager::serializeTreeToFile(HuffmanTree& huffmanTree, std::ofstream& outputStream) {
	if(outputStream) {
		std::vector<uchar> data = huffmanTree.getData();
		std::vector<ulong> frequencies = huffmanTree.getFrequencies();
		size_t dataSize = data.size();
		size_t nonZerofrequenciesCount = getAllNonZeroFrequenciesCount(frequencies);
		outputStream.write((char*)&nonZerofrequenciesCount, sizeof(nonZerofrequenciesCount));
		for(int i = 0; i < dataSize; i++) {
			if(frequencies[i] != 0) {
				outputStream.write((char*)&data[i], sizeof(data[i]));
				outputStream.write((char*)&frequencies[i], sizeof(frequencies[i]));
			}
		}
	} else {
		throw "Error while serializing the tree!";
	}
}

void FileManager::unpack(const std::string sourceFilename, const std::string destinationFilename) {
	TASK_UNPACKING_NOTIFIER;
	std::ifstream inputStream(sourceFilename, std::ios::binary);
	HuffmanTree huffmanTree = deserializeTreeFromFile(inputStream);
	std::ofstream outputStream(destinationFilename, std::ios::binary);

	if(inputStream && outputStream) {
		size_t codeSize = 0;
		while(true) {
			inputStream.read((char*)&codeSize, sizeof(codeSize));
			if(inputStream.eof()) {
				break;
			}
			std::vector<bool> code;
			char tmpChar;
			for(int i = 0; i < codeSize; i++) {
				inputStream.read((char*)&tmpChar, sizeof(tmpChar));
				code.push_back((bool)tmpChar);
			}
			uchar currentChar = huffmanTree.getLeafCharacterByCode(code);
			outputStream.write((char*)&currentChar, sizeof(currentChar));
		}
		inputStream.close();
		outputStream.close();
		TASK_COMPLETE_NOTIFIER;
	} else {
		throw "Error while unpacking the file!";
	}
}

HuffmanTree FileManager::deserializeTreeFromFile(std::ifstream& inputStream) {
	std::vector<uchar> data(MAX_CHARACTERS_COUNT);
	std::vector<ulong> frequencies(MAX_CHARACTERS_COUNT, 0);
	initializeCharacterVector(data);
	ulong frequency = 0;
	uchar character = 0;
	size_t huffmanTreeSize = 0;

	if(inputStream) {
		inputStream.read((char*)&huffmanTreeSize, sizeof(huffmanTreeSize));
		for(int i = 0; i < huffmanTreeSize; i++) {
			inputStream.read((char*)&character, sizeof(character));
			inputStream.read((char*)&frequency, sizeof(frequency));
			frequencies[character] = frequency;
		}
	} else {
		throw "Error while deserializing!";
	}
	return HuffmanTree(data, frequencies);
}