#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define LEN 20

void ToBinary(FILE* file, long n);
int validation(unsigned long* mas, int numb, unsigned long* validMas);
void TextFileWrite(FILE* file, unsigned long* validMas, int count);
void BinaryFileWrite(FILE* file, unsigned long* mas);


int main() {
     FILE *ftxt, *fbin;
     int numb = 0;
     unsigned long mas[MAX] = { 0 };
     unsigned long ValidatedMas[MAX] = { 0 };

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


void BinaryFileWrite(FILE* file, unsigned long* mas) {
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        mas[i] = (rand() << 32) + rand();
        ToBinary(file,mas[i]);
        printf("%ld\n", mas[i]);
    }
}


void TextFileWrite(FILE* file, unsigned long* validMas, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%ld\n", validMas[i]);
    }
    fclose(file);
}

//методом ділення
int validation(unsigned long* mas, int numb, unsigned long* validMas) {
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

void ToBinary(FILE* file,long n) {
    char result[32];
    for (int c = 16; c >= 0; c--) {
       int k = n >> c;
       if (k & 1) {
           result[c] = *("1");
           fprintf(file,"%c",result[c]);
       }
       else {
           result[c] = *("0");
           fprintf(file,"%c",result[c]);
       }
    }
}