#ifndef _INNER_NODE_H_
#define _INNER_NODE_H_

#include "Node.h"

class InnerNode : public Node {
public: 
	InnerNode();
	InnerNode(Node* firstNode, Node* secondNode);
	~InnerNode();
	Node* getLeftChild() const;
	Node* getRightChild() const;
	void serialize(std::ofstream& outputStream);
private:
	Node* leftChild;
	Node* rightChild;
};


#endif //_INNER_NODE_H_