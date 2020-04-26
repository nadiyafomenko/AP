#include <stdio.h>
#include <string.h>
#include "structFunc.h"

city setCity();

int Input(city* cities) {
	int q = 0;
	int k = 0;
	do {
		cities[k] = setCity();
		k++;
		puts("\nIf you want to add one more city press 1 (else 0):\n");
		scanf_s("%d", &q);
	} while (q == 1);

	return k;
}

int Percent(int counter, city*cities) {
	int percent = 0;
	for (int i = 0; i < counter; i++) {
		if ((2020 - cities[i].year) > 1200) {
			percent++;
		}
	}
	percent = (percent * 100) / counter;
	return percent;
}
city setCity() {
	
	city temp;
	getchar();
	puts("Enter city: ");
	gets_s(temp.name, 49);

	puts("Enter county: ");
	gets_s(temp.country, 49);

	puts("Enter year: ");
	scanf_s("%d", &temp.year);

	puts("Enter population: ");
	scanf_s("%d", &temp.population);

	return temp;
}

void printCity(int counter,city* cities) {
	puts("\n\n\tTable:\n");
	for (int i = 0; i < counter; i++) {
		printf("%s\t%s\t%d\t%d\n", cities[i].country, cities[i].name, cities[i].year, cities[i].population);
	}
	puts("\n");
}
