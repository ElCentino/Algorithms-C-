#include "Queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{

}

bool Queue::isEmpty()
{
	return (head == nullptr);
}

int Queue::peek()
{
	return *head->data;
}

void Queue::add(int *data)
{
	Node *node = new Node(data);

	if (tail != nullptr)
	{
		tail->next = node;
	}

	tail = node;

	if (head == nullptr)
	{
		head = node;
	}
}

int Queue::remove()
{

	int *data = head->data;
	head = head->next;

	if (head == nullptr)
	{
		tail = nullptr;
	}

	return *data;
}

void Queue::print()
{
	Node *current = head;

	std::cout << (current->next == nullptr) << std::endl;

	while (current->next != nullptr)
	{
		std::cout << *current->data << std::endl;

		current = current->next;
	}

	std::cout << *tail->data << std::endl;

	delete current;
}