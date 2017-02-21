#ifndef _GENERATED_PAIR_H_
#define _GENERATED_PAIR_H_

#include <vector>
#include "Commons.h"

class GeneratedPair {
public:
	GeneratedPair();
	GeneratedPair(uchar character, std::vector<bool>& huffmanCodes);
	void printPair() const;
	uchar getCharacter() const;
	std::vector<bool> getHuffmanCode() const;
private:
	std::vector<bool> huffmanCode;
	uchar character;
};



#endif //_GENERATED_PAIR_H_