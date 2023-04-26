#pragma once
#include "Node.h"

struct circularlyLinkedList
{
	Node* pHead = nullptr;

	void addTail(Node* node);

	void addHead(Node* node);

	void insertIndexK(int k, int data);

	void deleteTail();

	void deleteHead();

	void deleteIndexK(int k);

	void updateIndexK(int k, int data);


	int getSize();
};



