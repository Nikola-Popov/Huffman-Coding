#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <vector>
#include "Node.h"

class MinHeap {
public:
	MinHeap();
	MinHeap(std::vector<Node*>& otherData);
	void insert(Node* node);
	Node* getMinValue();
	size_t getHeapSize() const;
private:
	void siftUp(size_t index);
	void siftDown(size_t index);
	void Heapify();
private:
	std::vector<Node*> data;
};


#endif //_MIN_HEAP_H_