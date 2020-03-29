#pragma once
//шаблон структури
typedef struct Structcity {
	char name[50];
	int year;
	char country[50];
	int population;
} city;



//прототипи функцій
void printCity(city* c);
city setCity();
int setCities(city* cities, int* percent);
//void sortYear(city cities[10], int k);
void Percent(int p, int c);
void InsertionSort(city* cities, int k);


