#include <stdio.h>
#include "header.h"



int main() {
	int percent = 0;
	city cities[10];
	int count = setCities(cities, &percent);
	InsertionSort(cities, count);
	Percent(percent, count);
}
