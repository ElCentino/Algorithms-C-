#include "Mergesort.h"


Mergesort::Mergesort()
{

}


Mergesort::~Mergesort()
{

}

void Mergesort::sort(int array[], int left, int right)
{
	
	if (left > right)
		return;

	int midpoint = (left + right) / 2;

	sort(array, left, midpoint);
	sort(array, midpoint + 1, right);

	mergeHalve(array, new int[sizeof(array) / sizeof(int)], left, right);
}


void Mergesort::mergeHalve(int array[], int temp[], int left, int right)
{
	
}