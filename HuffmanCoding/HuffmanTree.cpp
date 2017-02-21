#include "HuffmanTree.h"
#include <iostream>

using namespace utility;

HuffmanTree::HuffmanTree() : root(nullptr) {
	std::vector<uchar> data(MAX_CHARACTERS_COUNT);
	std::vector<ulong> frequencies(MAX_CHARACTERS_COUNT, 0);
}

HuffmanTree::HuffmanTree(std::vector<uchar> data, std::vector<ulong> frequencies) {
	this->data = data;
	this->frequencies = frequencies;
	MinHeap minHeap;
	size_t dataSize = data.size();

	for(int i = 0; i < dataSize; i++) {
		if(frequencies[i] != 0) {
			minHeap.insert(new LeafNode(frequencies[i], data[i]));
		}
	}

	while(minHeap.getHeapSize() > 1) {
		Node* leftChild = minHeap.getMinValue();
		Node* rightChild = minHeap.getMinValue();
		Node* parent = new InnerNode(leftChild, rightChild);
		ulong calculatedFrequency = leftChild->getFrequency() + rightChild->getFrequency();
		parent->setFrequency(calculatedFrequency);
		minHeap.insert(parent);
	}
	root = minHeap.getMinValue();
}

std::vector<GeneratedPair> HuffmanTree::generateCodes() {
	std::vector<GeneratedPair> generatedPairs;
	std::vector<bool> codes;
	traverseTree(root, codes, generatedPairs);
	return generatedPairs;
}

void HuffmanTree::traverseTree(Node* node, std::vector<bool>& codes, std::vector<GeneratedPair>& generatedPairs) {
	if(LeafNode* leaf = dynamic_cast<LeafNode*>(node)) {
		generatedPairs.push_back(GeneratedPair(leaf->getCharacter(), codes));
	} else if(InnerNode* inner = dynamic_cast<InnerNode*>(node)) {
		std::vector<bool> leftCodes = codes;
		leftCodes.push_back(false);
		traverseTree(inner->getLeftChild(), leftCodes, generatedPairs);

		std::vector<bool> rightCodes = codes;
		rightCodes.push_back(true);
		traverseTree(inner->getRightChild(), rightCodes, generatedPairs);
	}
}

uchar HuffmanTree::getLeafCharacterByCode(std::vector<bool>& code) {
	return find(root, code);
}

uchar HuffmanTree::find(Node* node, std::vector<bool>& code) {
	if(code.empty()) {
		return ((LeafNode*)node)->getCharacter();
	}
	if(code[0]) {
		return find(((InnerNode *)node)->getRightChild(), eraseFirst(code));
	} else {
		return find(((InnerNode *)node)->getLeftChild(), eraseFirst(code));
	}
}

std::vector<uchar> HuffmanTree::getData() const {
	return data;
}

std::vector<ulong> HuffmanTree::getFrequencies() const {
	return frequencies;
}

bool HuffmanTree::isEmpty() const {
	return root == nullptr;
}