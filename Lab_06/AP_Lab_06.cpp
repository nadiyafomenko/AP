#include "structFunc.h"
#include "sortingFunc.h"
#include <stdio.h>


int main() {
	city cities[LEN];
	puts("Press enter no start:");
	int counter = Input(cities);

	printCity(counter,cities);	//Original table

	bubbleSort(counter, cities);	//Sorting
	printCity(counter,cities); //Sorted table

	printf("There are %d%% of cities built over 1200 years ago", Percent(counter,cities)); //percents	
}