#pragma once
class Bubblesort
{
public:
	Bubblesort();
	~Bubblesort();

	static void bubblesort(int[], int);

private:
	static void swap(int[], int, int);
};

