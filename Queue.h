#pragma once

#include <iostream>

class Queue
{
public:
	Queue();
	~Queue();

public:
	static class Node 
	{
	public:
		Node* next;
		int* data;

		Node(int *data)
		{
			this->data = data;
		}
			
	};

	bool isEmpty();
	int peek();
	int remove();
	void add(int *data);
	void print();

	Node *tail;
	Node *head;
};

