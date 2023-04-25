#include "Stack.h"

void Stack::addHead(Node* node)
{
	if (pHead == nullptr)
	{
		pHead = node;
		pTail = node;
	}
	else
	{
		node->Next = pHead;
		pHead = node;
	}
}

void Stack::deleteHead()
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
