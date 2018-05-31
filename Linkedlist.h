#pragma once
#include <iostream>

class Linkedlist
{
public:
	Linkedlist();
	~Linkedlist();

private:

	class Node {

	public:
		int* data;
		Node* next;

		Node(int*);
		~Node();
	};

	Node* head;

public:
	void append(int*);
	void prepend(int*);
	void remove(int*);
	void print();

};

