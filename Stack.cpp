#include "Stack.h"


Stack::Stack()
{

}

Stack::~Stack()
{
	delete top;
}

int Stack::peek()
{
	return *top->data;
}

void Stack::push(int* data)
{
	Node* node = new Node(data);
	node->next = top;

	top = node;

	delete node;
}

int Stack::pop()
{
	int data = *top->data;

	top = top->next;

	return data;
}

bool Stack::isEmpty()
{
	return top == nullptr;
}

Stack::Node::~Node() 
{
	delete next;
	delete data;
}

Stack::Node::Node(int* data)
{
	this->data = data;
}