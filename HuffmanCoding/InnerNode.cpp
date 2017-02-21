#include "InnerNode.h"

InnerNode::InnerNode() : leftChild(nullptr), rightChild(nullptr) {
}

InnerNode::InnerNode(Node* firstNode, Node* secondNode) : InnerNode() {
	leftChild = firstNode;
	rightChild = secondNode;
}

InnerNode::~InnerNode() {
	delete leftChild;
	delete rightChild;
}

Node* InnerNode::getLeftChild() const {
	return leftChild;
}

Node* InnerNode::getRightChild() const {
	return rightChild;
}

void InnerNode::serialize(std::ofstream& outputStream) {
	ulong frequency = getFrequency();
	outputStream.write((char*)&frequency, sizeof(frequency));
	outputStream.write((char*)&leftChild, sizeof(leftChild));
	outputStream.write((char*)&rightChild, sizeof(rightChild));
}