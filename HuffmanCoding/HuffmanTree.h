#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_

#include <vector>
#include <string>
#include <fstream>
#include "MinHeap.h"
#include "Node.h"
#include "LeafNode.h"
#include "InnerNode.h"
#include "GeneratedPair.h"
#include "Commons.h"

class HuffmanTree {
public:
	HuffmanTree();
	HuffmanTree(std::vector<uchar> data, std::vector<ulong> frequencies);
	std::vector<GeneratedPair> generateCodes();
	std::vector<uchar> getData() const;
	std::vector<ulong> getFrequencies() const;
	bool isEmpty() const;
	uchar getLeafCharacterByCode(std::vector<bool>& code);
private:
	void traverseTree(Node* node, std::vector<bool>& codes, std::vector<GeneratedPair>& generatedPairs);
	uchar find(Node* node, std::vector<bool>& code);
private:
	std::vector<uchar> data;
	std::vector<ulong> frequencies;
	Node* root;
};

#endif //_HUFFMAN_TREE_H_
