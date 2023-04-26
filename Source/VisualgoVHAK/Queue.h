#pragma once
#include "Node.h"

struct Queue
{
	Node* pHead = nullptr;
	Node* pTail = nullptr;

	void addTail(Node* node);

	void deleteHead();

	void deleteIndexK(int k);


	int getSize();
};



