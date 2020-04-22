#include <stdio.h>
#include <ctype.h>

#define LEN 200
#define KST 3

char* FindNumber(char* s);
long GetNumber(char** next);
void Print();

int numbs[LEN][LEN] = { 0 };

int main()
{
	char string[LEN];
	int j = 0;
	while (j < KST) {
		int i = 1;
		printf("Enter a string: ");
		gets_s(string, LEN);
		char* pnum = string;
		while ((pnum = FindNumber(pnum)) != NULL) {
			numbs[j][i] = GetNumber(&pnum);
			if (*pnum == '\0') break;
			i++;	
		}
		numbs[j][0] = i;
		j++;
	}
	Print();
	getchar();
}


void Print() {
	for (int r = 0; r < KST; r++) {
		for (int i = 1; i <= numbs[r][0]; i++) {
			printf("%d\t", numbs[r][i]);
		}
		puts("\n");
	}
	
}

char* FindNumber(char* s)
{
	while (!(*s <= '9') && *s > '0') s++;
	return s;
}

long GetNumber(char** next)
{
	char* pn = *next;
	long numb = 0;
	while (*pn >= '0' && *pn <= '9') {
		numb = numb * 10 + (*pn - 48);
		pn++;
	}
	*next = pn;
	return numb;
}