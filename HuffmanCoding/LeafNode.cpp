#include "LeafNode.h"

LeafNode::LeafNode() {
}

LeafNode::LeafNode(ulong frequency, uchar character) : Node(frequency), character(character) {
}

LeafNode::~LeafNode() {
}

uchar LeafNode::getCharacter() const {
	return character;
}

void LeafNode::serialize(std::ofstream& outputStream) {
	ulong frequency = getFrequency();
	outputStream.write((char*)&frequency, sizeof(frequency));
	outputStream.write((char*)&character, sizeof(character));
}

