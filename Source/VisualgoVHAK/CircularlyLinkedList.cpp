#include "CircularlyLinkedList.h"
#include <iostream>

void circularlyLinkedList::addTail(Node* node)
{
    if (pHead == nullptr)
    {
        pHead = node;
        node->Next = pHead;
    }
    else
    {
        Node* current = pHead;
        while (current->Next != pHead)
        {
            current = current->Next;
        }
        current->Next = node;
        node->Next = pHead;
    }
}

void circularlyLinkedList::addHead(Node* node)
{
    if (pHead == nullptr)
    {
        pHead = node;
        node->Next = pHead;
    }
    else
    {
        Node* current = pHead;
        while (current->Next != pHead)
        {
            current = current->Next;
        }
        current->Next = node;
        node->Next = pHead;
        pHead = node;
    }
}

void circularlyLinkedList::deleteTail()
{
    if (pHead == nullptr) return;

    if (pHead->Next == pHead)
    {
        delete pHead;
        pHead = nullptr;
        return;
    }

    Node* current = pHead;
    while (current->Next->Next != pHead)
    {
        current = current->Next;
    }

    delete current->Next;
    current->Next = pHead;
}

void circularlyLinkedList::deleteHead()
{
    if (pHead == nullptr) return;

    if (pHead->Next == pHead)
    {
        delete pHead;
        pHead = nullptr;
        return;
    }

    Node* current = pHead;
    while (current->Next != pHead)
    {
        current = current->Next;
    }

    Node* temp = pHead;
    current->Next = pHead->Next;
    pHead = pHead->Next;
    delete temp;
}

void circularlyLinkedList::deleteIndexK(int k)
{
    int count = 0;
    if (pHead == nullptr) return;
    if (k > getSize()) return;
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

void circularlyLinkedList::insertIndexK(int k, int data)
{
    int count = 0;
    Node* cur = pHead;
    Node* prev = nullptr;
    if (k >= getSize()) return;
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
}

void circularlyLinkedList::updateIndexK(int k, int data)
{
    if (k > getSize()) return;
    insertIndexK(k, data);
    deleteIndexK(k + 1);
}

int circularlyLinkedList::getSize()
{
    int ret = 0;
    Node* cur = pHead;
    if (cur != nullptr) {
        ret++;
        cur = cur->Next;
    }
    while (cur != nullptr && cur != pHead)
    {
        ret++;
        cur = cur->Next;
    }
    return ret;
}
