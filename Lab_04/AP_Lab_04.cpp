#include <stdio.h>
#include <string.h>

#define LEN 100

void findwords(char* s);
void printWord(char* s, int k);

int count = 0;
int k = 0;

int main() {
	char s[LEN];
	gets_s(s, LEN);
	findwords(s);
	printf("%d", count);
}

void findwords(char* s) {
	if (*s != ' ' && *s != '\0') k++;
	if (*s == '\0') {
		if (*(s - 1) == *(s - k)) printWord(s - k, k);
		count++;
		return;
		k = 0;
	}
	if (*s == ' ') {
		if (*(s - 1) == *(s - k)) printWord(s - k, k);
		count++;
		k = 0;
	}
	findwords(s + 1);
}

void printWord(char* s, int k) {
	for (int i = 0; i < k; i++) {
		printf("%c", *(s + i));
	}
	puts("\t");
}