#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define LEN 20

int validation(long* mas, int numb, long* validMas);
void TextFileWrite(FILE* file, long* validMas, int count);
void BinaryFileWrite(FILE* file, long* mas);


int main() {
     FILE*ftxt, *fbin;
     int numb = 0;
     long mas[MAX] = { 0 };
     long ValidatedMas[MAX] = { 0 };

     printf("enter a control number:\n");
     scanf_s("%d",&numb);

     fbin = fopen("D:\\randoms.bin", "wb+");
     BinaryFileWrite(fbin, mas);
     printf("D:\\randoms.bin is ready ...\n");
     fclose(fbin);

     ftxt = fopen("D:\\randoms.txt", "w");
     int count = validation(mas, numb, ValidatedMas);
     TextFileWrite(ftxt, ValidatedMas, count);
     printf("D:\\randoms.txt is ready ...");
}


void BinaryFileWrite(FILE* file, long* mas) {
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        mas[i] = (rand() << 32) + rand();
        fprintf(file, " %ld  ", mas[i]);
        printf("%d\n", mas[i]);
    }
}


void TextFileWrite(FILE* file, long* validMas, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%ld\n", validMas[i]);
    }
    fclose(file);
}


int validation(long* mas, int numb, long* validMas) {
    int count = 0;
        for (int i = 0; i < MAX; i++) {
            char str[LEN];
            sprintf(str, "%ld", mas[i]);
            for (int j = 0; j < LEN; j++) {
                if (str[j] == (numb + 48)) {
                    validMas[count] = mas[i];
                    count++;
                    break;
                }
            }
        }
        return count;
}

