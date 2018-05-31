#include "Linkedlist.h"


Linkedlist::Linkedlist()
{
	
}


Linkedlist::~Linkedlist()
{
	delete head;
}

void Linkedlist::append(int* data) 
{
	if (head == nullptr)
	{
		head = new Node(data);
		return;
	}
	
	Node* current = head;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = new Node(data);
}

void Linkedlist::prepend(int* data)
{
	Node* node = new Node(data);
	node->next = head;

	head = node;
}

void Linkedlist::remove(int* data)
{
	if (head == nullptr)
	{
		return;
	} 
	else if (head->data == data)
	{
		head = head->next;
		return;
	}
	else
	{
		Node* current = head;

		while (current->next != nullptr)
		{
			if (current->next->data == data)
			{
				current->next = current->next->next;
			}

			current = current->next;
		}
	}
}

void Linkedlist::print(void)
{
	Node* current = head;

	while (current->next != nullptr)
	{
		std::cout << *current->data << std::endl;
		current = current->next;
	}

	std::cout << *current->data << std::endl;
}

Linkedlist::Node::Node(int* data)
{
	this->data = data;
}

Linkedlist::Node::~Node()
{
	delete next;
	delete data;
}


