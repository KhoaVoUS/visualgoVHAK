#pragma once
#include "Node.h"
struct doublyLinkedList
{
	Node* pHead = nullptr;
	Node* pTail = nullptr;

	void addTail(Node* node);

	void addHead(Node* node);

	void insertIndexK(int k, int data);

	void deleteTail();

	void deleteHead();

	void deleteIndexK(int k);

	void updateIndexK(int k, int data);

	void loadList();

	int getSize();
};



