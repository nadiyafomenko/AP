#include <stdio.h>
#include <string.h>

#define LEN 100

int findwords(char*);
void findwords_iter(char* s);

int main() {
	char s[LEN];
	gets_s(s, LEN);
	findwords_iter(s);
}

//recursion
int findwords(char* s) {
	if (!*s) return 0;
	char* p = s;
	while (*s && *s != ' ') s++;
	*s = 0;

	int count = findwords(s + 1);
	if (*p == *(s - 1)) {
		puts(p);
		count++;
	}
	return count;
}

//iter
void findwords_iter(char* s) {
	char* p = s, * _p = s;
	int k = 0;

	while (*++s) {
		if (*s == ' ') {
			k++;
			_p = s - 1;
			if (*p == *_p)
				for (p; *(p) != ' '; ++p)
					printf("%c", *p);

			p = s + 1;
		}
	}
	if (*(s - 1) == *p)
		for (p; *(p) != '\0'; ++p)
			printf("%c", *p);
	if (k == 0)
		if (p == _p) {
			for (p; *(p) != '\0'; ++p) printf("%c", *p);
		}
}

