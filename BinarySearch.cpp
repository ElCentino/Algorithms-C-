#include "BinarySearch.h"


BinarySearch::BinarySearch()
{
	
}


BinarySearch::~BinarySearch()
{

}

bool BinarySearch::search(int list[], int left, int right, int target)
{
	if (left > right)
	{
		return false;
	}

	int midpoint = (left + right) / 2;

	if (list[midpoint] == target)
	{
		cout << "Number : " << target << " was found at position " << list[midpoint] << endl;

		return true;
	}

	else if (list[midpoint] > target)
	{
		return search(list, left, midpoint - 1, target);

		
	}

	else
	{
		return search(list, midpoint + 1, right, target);
	}
}