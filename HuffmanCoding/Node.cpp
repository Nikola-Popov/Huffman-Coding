#include "Node.h"

Node::Node() : frequency(0) {
}

Node::Node(const Node& other) {
	frequency = other.frequency;
}

Node::Node(ulong frequency) : frequency(frequency) {
}

Node::~Node() {
}

ulong Node::getFrequency() const {
	return frequency;
}

void Node::setFrequency(ulong frequency) {
	this->frequency = frequency;
}

