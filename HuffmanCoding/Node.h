#ifndef _NODE_H_
#define _NODE_H_

#include "Commons.h"
#include <fstream>

class Node {
public:
	Node();
	Node(ulong frequency);
	Node(const Node&);
	virtual ~Node();
	ulong getFrequency() const;
	void setFrequency(ulong frequnecy);
protected:
	virtual void serialize(std::ofstream& outputStream) = 0;
private:
	ulong frequency;
};

#endif //_NODE_H_