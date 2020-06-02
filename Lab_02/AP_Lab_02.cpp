#include <stdio.h>
#include <ctype.h>

#define LEN 200
#define KST 5

void Print(int(*numbs)[LEN]);
void getNumbs(char* p, int* row);


int main()
{
	int numbs[LEN][LEN] = { 0 };
	char string[LEN];
	for (int j = 0; j < KST; j++) {
		int i = 1;
		printf("Enter a string: ");
		gets_s(string, LEN);
		getNumbs(string, numbs[j]);
	}
	Print(numbs);
}

int max(int* numbs) {
	int max = numbs[0];
	for (int i = 0; i < KST; i++) {
		if (numbs[i] > max) max = numbs[i];
	}
	return max;
}

void Print(int (*numbs)[LEN]) {
	for (int r = 0; r < KST; r++) {
		int* ptr = (int*)numbs[r];
		for (int i = 1; i <= (*ptr); i++) {
			printf("%d\t", *(ptr + i));
		}
		puts("\n");
	}
	
}

void getNumbs(char* string, int* row) {
	int* p_row = row + 1;
	long num;
	while (*string) {
		while (*string && (*string < '0' || *string > '9'))
			string++;
		num = 0;
		while (*string && *string > '0' && *string <= '9')
			num = num * 10 + (*string++ - '0');
		*p_row++ = num;
		++* (row);
	}
}
