#pragma once
struct Node {
	int data = 0;
	Node* Next = nullptr;
	Node* Prev = nullptr;
};


Node* create(int data);

