#include "Tree.h"


Tree::Tree(int data)
{
	this->data = data;
}


Tree::~Tree()
{
	delete left;
	delete right;
}

void Tree::insert(int value)
{
	if (value <= data)
	{
		if (left == nullptr)
		{
			left = new Tree(value);
		}
		else 
		{
			left->insert(value);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new Tree(value);
		} 
		else
		{
			right->insert(value);
		}
	}
}

bool Tree::contains(int value)
{
	if (value == data)
	{
		return true;
	}
	else if (value < data)
	{
		if (left == nullptr)
		{
			return false;
		} 
		else
		{
			return left->contains(value);
		}
	} 
	else
	{
		if (right == nullptr)
		{
			return false;
		}
		else 
		{
			return right->contains(value);
		}
	}
}

void Tree::treverse()
{
	if (left != nullptr)
	{
		left->treverse();
	}

	std::cout << data << std::endl;

	if (right != nullptr)
	{
		right->treverse();
	}
}