#pragma once
#include "Node.h"

struct Stack
{
	Node* pHead = nullptr;
	Node* pTail = nullptr;


	void addHead(Node* node);

	void deleteHead();

	int getSize();
};



