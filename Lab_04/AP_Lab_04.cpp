#include <stdio.h>
#include <string.h>

#define LEN 100

int findwords(char* s, char* mas[LEN]);
void Print(char* mas[LEN], int k);


int main() {
	char* mas[LEN];
	char s[LEN];
	gets_s(s, LEN);
	int count = findwords(s,mas);
	Print(mas, count);
}

int findwords(char* s, char* mas[LEN]) {
	if (!*(s+1)) return 0;
	char* p = s;
	while (*s && *s != ' ') s++;
	*s = 0;

	int count = findwords(s + 1,mas);
	if (*p == *(s - 1)) {
		mas[count] = p;
		count++;
	}
	return count;
}

void Print(char* mas[LEN], int k) {
	for (int i = 0; i < k; i++) {
		puts(mas[i]);
	}
}