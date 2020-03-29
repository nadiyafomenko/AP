#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN 100
#define KST 5

char* FindNumber(char* s);
long GetNumber(char* pn, char** next);

int main() {
	char strings[LEN][LEN];
	int i = 0;
	int p = 0;
	int k = 0;
	while (k < KST) {
		printf("Enter a string:\n");
		gets_s(strings[i], LEN);
		i++;
		k++;
	}
	int j = 0;
	printf("\n\n%d",k);

	while (k != 0) {

		char* pnum = strings[j];

		while ((pnum = FindNumber(pnum)) != NULL) {
			printf("%d\t", GetNumber(pnum, &pnum));
			if (*pnum == '\0') break;
		}
		j++;
		k--;
		puts("\n");
	}

	system("pause");
	return 0;

}


char* FindNumber(char* s) {
	while (!isdigit(*s) && *s != '0')
		s++;
	if (*s == '\0') return NULL;
	else return s;
}

long GetNumber(char* pn, char** next) {
	long numb = 0;
	while (isdigit(*pn)) {
		numb = numb * 10 + (*pn - 48);
		pn++;
	}
	*next = pn;
	return numb;
}