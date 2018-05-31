#pragma once

#include <iostream>

using namespace std;

class Mergesort
{
public:
	Mergesort();
	~Mergesort();

	static void sort(int[], int, int);
	static void mergeHalve(int[], int[], int, int);

};

