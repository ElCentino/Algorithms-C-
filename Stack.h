#pragma once
#include <iostream>

using namespace std;

class Stack
{
public:
	Stack();
	~Stack();

	void push(int*);
	int peek();
	int pop();
	bool isEmpty();

private:
	static class Node {

	public:
		Node* next;
		int* data;
		
		Node(int*);
		~Node();
	};

private :
	Node* top;

};

