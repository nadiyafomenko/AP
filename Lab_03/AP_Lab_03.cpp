#include <stdio.h>
#include <string.h>

#define LEN 10

//шаблон структури
typedef struct {
	char name[50];
	int year;
	char country[50];
	int population;
} city;

city c;

int Input(); // функція заповнення масиву структур 
int Percent(); //розрахування відсотку
city setCity(); //функція заповнення структури
void printCity(); //функція роздруку таблиці
void bubbleSort(); // функція сортування методом бульбашки
void InsertionSort(); // функція сортування методом вставок

city cities[LEN];
int counter;

int main() {
	puts("Press enter no start:");
	counter = Input();

	printCity();	//Original table

	InsertionSort();	//Sorting
	printCity(); //Sorted table

	printf("There are %d%% of cities built over 1200 years ago", Percent()); //percents	
}


//ФУНКЦІЇ

int Input() {
	int q = 0;
	int counter = 0;
	do {
		cities[counter] = setCity();
		counter++;
		puts("\nIf you want to add one more city press 1 (else 0):\n");
		scanf_s("%d", &q);
	} while (q == 1);

	return counter;
}

int Percent() {
	int percent = 0;
	for (int i = 0; i < counter; i++) {
		if ((2020 - cities[i].year) > 1200) {
			percent++;
		}
	}
	return (percent * 100) / (float)counter;
}
city setCity() {
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

void printCity() {
	puts("\n\n\tTable:\n");
	for (int i = 0; i < counter; i++) {
		printf("%s\t%s\t%d\t%d\n", cities[i].country, cities[i].name, cities[i].year, cities[i].population);
	}
	puts("\n");
}


void bubbleSort()
{
	city c;
	for (int j = counter; j > 0; j--)
	{
		for (int i = counter; i > 0; i--)
		{
			if (cities[i].year > cities[i - 1].year)
			{
				c = cities[i - 1];
				cities[i - 1] = cities[i];
				cities[i] = c;
			}
		}
	}
}

void InsertionSort()
{
	int location;
	city c;

	for (int i = 1; i < counter; i++)
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

}