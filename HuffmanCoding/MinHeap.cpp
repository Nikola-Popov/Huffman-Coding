#include "MinHeap.h"

MinHeap::MinHeap() {
}

MinHeap::MinHeap(std::vector<Node*>& otherData) {
	for(int i = 0; i < otherData.size(); i++) {
		data[i] = otherData[i];
	}
}

void MinHeap::Heapify() {
	size_t dataSize = data.size();
	for(int i = dataSize; i >= 0; i--) {
		siftDown(i);
	}
}

void MinHeap::insert(Node* node) {
	data.push_back(node);
	size_t lastElementIndex = data.size() - 1;
	siftUp(lastElementIndex);
}

Node* MinHeap::getMinValue() {
	Node* minValueData = data[0];
	size_t firstElementIndex = 0;
	size_t lastElementIndex = data.size() - 1;
	data[0] = data[lastElementIndex];
	data.pop_back();
	siftDown(firstElementIndex);
	return minValueData;
}

void MinHeap::siftUp(size_t index) {
	if(index == 0) {
		return;
	}

	size_t parentIndex = (index - 1) / 2;
	if(data[parentIndex]->getFrequency() > data[index]->getFrequency()) {
		Node* tmp = data[parentIndex];
		data[parentIndex] = data[index];
		data[index] = tmp;
		siftUp(parentIndex);
	}
}

void MinHeap::siftDown(size_t index) {
	size_t dataSize = data.size();
	size_t leftChildIndex = 2 * index + 1;
	size_t rightChildIndex = 2 * index + 2;
	size_t minIndex = index;

	if(leftChildIndex >= dataSize) {
		return; //index is leaf
	}
	if(data[index]->getFrequency() > data[leftChildIndex]->getFrequency()) {
		minIndex = leftChildIndex;
	}
	if((rightChildIndex < dataSize) && (data[minIndex]->getFrequency() > data[rightChildIndex]->getFrequency())) {
		minIndex = rightChildIndex;
	}
	if(index != minIndex) {
		Node* tmp = data[index];
		data[index] = data[minIndex];
		data[minIndex] = tmp;
		siftDown(minIndex);
	}
}

size_t MinHeap::getHeapSize() const {
	return data.size();
}