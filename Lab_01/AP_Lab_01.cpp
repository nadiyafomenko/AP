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

//прототипи функцій
int Percent(city cities[LEN], int k); //розрахування відсотку
city setCity(); //функція заповнення структури
void printCity(city* c, int k); //функція роздруку таблиці
void sortYear(city cities[LEN], int k); // функція сортування



int main() {

	int q = 0;
	int counter = 0;
	city cities[LEN];
	puts("Press enter no start:");
	do {
		cities[counter] = setCity();
		counter++;
		puts("\nIf you want to add one more city press 1 (else 0):\n");
		scanf_s("%d", &q);
	} while (q == 1);

	printCity(cities, counter);	//Original table

	sortYear(cities, counter);	//Sorting
	printCity(cities, counter); //Sorted table

	printf("There are %d%% of cities built over 1200 years ago",Percent(cities, counter)); //percents	
}


//ФУНКЦІЇ
int Percent(city cities[LEN], int k) {
	int percent = 0;
	
	for (int i = 0; i < k; i++) {
		if ((2020 - cities[i].year) > 1200) {
			percent++;
		}
	}
	return (percent * 100) / (float)k;
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

void printCity(city cities[LEN], int k) {
	
	puts("\n\n\tTable:\n");
	for (int i = 0; i < k; i++) {
		printf("%s\t%s\t%d\t%d\n", cities[i].country, cities[i].name, cities[i].year, cities[i].population);
	}
	puts("\n");
}


void sortYear(city cities[LEN], int k)
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
}


