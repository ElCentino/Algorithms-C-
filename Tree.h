#pragma once
#include <iostream>

class Tree
{
public:
	Tree(int);
	~Tree();
	
	void insert(int);
	bool contains(int);
	void treverse();

private:
	Tree* left;
	Tree* right;

	int data;

};

