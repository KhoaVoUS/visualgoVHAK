#include "SinglyLinkedList.h"
#include <iostream>


void singlyLinkedList::addTail(Node* node)
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

void singlyLinkedList::addHead(Node* node)
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

void singlyLinkedList::deleteTail()
{
	if (pTail == nullptr) return;

	if (pHead == pTail)
	{
		delete pTail;
		pHead = nullptr;
		pTail = nullptr;
		return;
	}

	Node* current = pHead;
	while (current->Next != pTail)
	{
		current = current->Next;
	}

	delete pTail;
	pTail = current;
	pTail->Next = nullptr;
}

void singlyLinkedList::deleteHead()
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

void singlyLinkedList::deleteIndexK(int k)
{
	int count = 0;
	if (pHead == nullptr) return;

	if (k == 0)
	{
		deleteHead();
		return;
	}

	Node* cur = pHead;
	Node* prev = nullptr;
	while (cur != nullptr && count < k)
	{
		prev = cur;
		cur = cur->Next;
		count++;
	}

	if (cur == nullptr)
	{
		deleteTail();
		return;
	}

	if (prev == nullptr)
	{
		// kth node is the head node
		pHead = cur->Next;
	}
	else
	{
		prev->Next = cur->Next;
	}

	delete cur;

}
void singlyLinkedList::insertIndexK(int k, int data)
{
	int count = 0;
	Node* cur = pHead;
	Node* prev = nullptr;

	if (k <= 0)
	{
		addHead(create(data));
		return;
	}

	while (cur != nullptr && count < k)
	{
		prev = cur;
		cur = cur->Next;
		count++;
	}

	Node* temp = create(data);

	if (cur == nullptr)
	{
		addTail(temp);
		return;
	}

	if (prev != nullptr)
	{
		prev->Next = temp;
	}
	else
	{
		pHead = temp;
	}

	temp->Next = cur;
	return;
}

void singlyLinkedList::updateIndexK(int k, int data)
{
	insertIndexK(k, data);
	deleteIndexK(k + 1);
}
void singlyLinkedList::loadList()
{
	Node* cur = pHead;
	while (cur != nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->Next;
	}
}

int singlyLinkedList::getSize()
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