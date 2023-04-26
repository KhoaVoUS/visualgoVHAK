#include "Queue.h"
#include <iostream>


void Queue::addTail(Node* node)
{
	if (pHead == nullptr)
	{
		pHead = node;
		pTail = node;
	}
	else
	{
		pTail->Next = node;
		pTail = node;
	}
}


void Queue::deleteHead()
{
	if (pHead == nullptr) return;

	if (pHead->Next == nullptr)
	{
		delete pHead;
		pHead = nullptr;
		return;
	}

	Node* temp = pHead->Next;
	delete pHead;
	pHead = temp;
}

int Queue::getSize()
{
	int ret = 0;
	Node* cur = pHead;
	while (cur != nullptr)
	{
		ret++;
		cur = cur->Next;
	}
	return ret;
}