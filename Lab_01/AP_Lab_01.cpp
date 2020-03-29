#include <stdio.h>

//шаблон структури
typedef struct city {
	char name[50];
	int year;
	char country[50];
	int population;
} city;

city c;
//прототипи функцій
void Percent(int p, int c); //розрахування відсотку
city setCity(); //функція заповнення структури
void printCity(city* c); //функція роздруку таблиці
void sortYear(city cities[10], int k); // функція сортування


//ЗАВДАННЯ:
//оголошення через typedef, визначення відсотків у окремій функції, передача у функцію структури через вказівник


int main() {

	int q = 0;
	int i = 0;
	int counter = 0;
	int percent = 0;
	city cities[10];
	puts("Press enter no start:");

	do {
		city city1 = setCity();
		cities[i] = city1;
		counter++;
		i++;
		if (city1.year < 1200) {
			percent++;
		}
		puts("\nIf you want to add one more city press 1 (else 0):\n");
		scanf_s("%d", &q);
	} while (q == 1);
	//виведення початкової таблиці
	puts("\n\n\tTable:\n");
	for (int i = 0; i < counter; i++) {
		printCity(cities);
	}
	puts("\n");

	//виведення відсортованої по роках таблиці (по спаданню)
	sortYear(cities, counter);
	printf("\n\n\tSorted table:\n");
	for (int i = 0; i < counter; i++) {
		printCity(cities);
	}

	Percent(percent, counter);

}



//ФУНКЦІЇ
void Percent(int p, int c) {
	printf("percentage of cities under 1200 - %d%%", (100 * p) / c);
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

void printCity(city* c) {
	printf("%s		%s		%d		%d\n", c->country, c->name, c->year, c->population);
}


void sortYear(city cities[10], int k)
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


