#include "header.h"
#include <stdio.h>

int setCities(city* cities, int* percent) {
	int counter = 0;
	int i = 0;
	int q = 0;
	puts("Press enter no start:");
	do {
		city city1 = setCity();
		cities[i] = city1;
		counter++;
		i++;
		if (city1.year < 1200) {
			(*percent)++;
		}
		puts("\nIf you want to add one more city press 1 (else 0):\n");
		scanf_s("%d", &q);
	} while (q == 1);

	puts("\n\n\tTable:\n");
	for (int i = 0; i < counter; i++) {
		printCity(cities + i);
	}

	return counter;
}

city setCity() {

	city c;
	getchar();
	puts("Enter city: ");

	gets_s(c.name, 49);

	puts("Enter county: ");
	gets_s(c.country, 49);

	puts("Enter year: ");
	scanf_s("%d", &c.year);

	puts("Enter population: ");
	scanf_s("%d", &c.population);

	return c;
}

void printCity(city* c) {

	printf("%s		%s		%d		%d\n", c->country, c->name, c->year, c->population);
}


//bubble sort
void sortYear(city* cities, int k)
{

	city c;
	for (int j = k; j > 0; j--)
	{
		for (int i = k; i > 0; i--)
		{
			if (cities[i].year > cities[i - 1].year)
			{
				c = cities[i - 1];
				cities[i - 1] = cities[i];
				cities[i] = c;
			}
		}
	}

	puts("\n\n\tSorted Table:\n");
	for (int i = 0; i < k; i++) {
		printCity(cities + i);
	}
}
//

void Percent(int p, int c) {
	printf("percentage of cities under 1200 - %d%%", (100 * p) / c);
}

//Insertion Sort
void InsertionSort(city* cities, int k)
{
	int newElement, location;
	city c;

	for (int i = 1; i < k; i++)
	{
		c = cities[i];
		location = i - 1;
		while (location >= 0 && cities[location].year > c.year)
		{
			cities[location + 1] = cities[location];
			location = location - 1;
		}
		cities[location + 1] = c;
	}

	puts("\n\n\tSorted Table:\n");
	for (int i = 0; i < k; i++) {
		printCity(cities + i);
	}
}
//