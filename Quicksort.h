#pragma once
#include <iostream>

using namespace std;

class Quicksort
{
public:
	Quicksort();
	~Quicksort();
	
	static void quicksort(int[], int, int);

private:
	static int partition(int[], int, int, int);
	static void swap(int[], int, int);
};

