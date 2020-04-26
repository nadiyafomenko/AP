#include "sortingFunc.h"

void bubbleSort(int counter, city* cities)
{
	city temp;
	for (int j = counter; j > 0; j--)
	{
		for (int i = counter; i > 0; i--)
		{
			if (cities[i].year > cities[i - 1].year)
			{
				temp = cities[i - 1];
				cities[i - 1] = cities[i];
				cities[i] = temp;
			}
		}
	}
}

void InsertionSort(int counter, city* cities)
{
	int location;
	city temp;

	for (int i = 1; i < counter; i++)
	{
		temp = cities[i];
		location = i - 1;
		while (location >= 0 && cities[location].year > temp.year)
		{
			cities[location + 1] = cities[location];
			location = location - 1;
		}
		cities[location + 1] = temp;
	}

}