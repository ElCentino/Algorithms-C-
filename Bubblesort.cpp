#include "Bubblesort.h"


Bubblesort::Bubblesort()
{
}


Bubblesort::~Bubblesort()
{
}

void Bubblesort::bubblesort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i] < array[j])
			{
				swap(array, i, j);
			}
		}
	}
}

void Bubblesort::swap(int list[], int left, int right)
{
	int temp = list[left];
	list[left] = list[right];
	list[right] = temp;
}
