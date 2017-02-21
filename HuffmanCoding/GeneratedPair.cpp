#include "GeneratedPair.h"
#include <iostream>

GeneratedPair::GeneratedPair() {
}

GeneratedPair::GeneratedPair(uchar character, std::vector<bool>& huffmanCode) :character(character), huffmanCode(huffmanCode) {
}

void GeneratedPair::printPair() const {
	std::cout << "Char: " << character << " | ";
	std::cout << "Code: ";
	size_t huffmanCodeSize = huffmanCode.size();
	for(int i = 0; i < huffmanCodeSize; i++) {
		std::cout << (int)huffmanCode[i];
	}
	std::cout << std::endl;
}

uchar GeneratedPair::getCharacter() const {
	return character;
}

std::vector<bool> GeneratedPair::getHuffmanCode() const {
	return huffmanCode;
}