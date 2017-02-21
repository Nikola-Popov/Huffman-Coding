#ifndef _LEAF_NODE_H_
#define _LEAF_NODE_H_

#include "Commons.h"
#include "Node.h"

class LeafNode : public Node {
public:
	LeafNode();
	LeafNode(ulong frequency, uchar character);
	~LeafNode();
	uchar getCharacter() const;
	void serialize(std::ofstream& outputStream);
private:
	uchar character;
};


#endif //_LEAF_NODE_H_