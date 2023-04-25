#include "Node.h"

Node* create(int data)
{
	Node* node = nullptr;
	node = new Node;
	node->data = data;
	node->Next = nullptr;
	return node;
}
