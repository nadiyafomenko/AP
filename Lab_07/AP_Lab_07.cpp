#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define LEN 20

void validation(long* mas, int numb, long* validMas);
int v = 0;

int main() {
     FILE*ftxt, *fbin;
     int numb = 0;
     long mas[MAX] = { 0 };
     long ValidatedMas[MAX] = { 0 };

     srand(time(0));

     printf("enter a control number:\n");
     scanf_s("%d",&numb);

     fbin = fopen("D:\\randoms.bin", "wb+");

     for (int i = 0; i < MAX; i++) {
         mas[i] = rand() * rand();
         fprintf(fbin, " %d  ", mas[i]); 
         printf("%d\n", mas[i]);
     }
     printf("Binary file is ready...\n");
     fclose(fbin);
    
     ftxt = fopen("D:\\randoms.txt", "w");
     validation(mas, numb, ValidatedMas);
     for (int i = 0; i < v; i++) {
         fprintf(ftxt, "%d\n", ValidatedMas[i]);
     }
     
     fclose(ftxt);
}

void validation(long* mas, int numb, long* validMas) {


        for (int i = 0; i < MAX; i++) {
            char str[LEN];
            sprintf(str, "%d", mas[i]);
            for (int j = 0; j < LEN; j++) {
                if (str[j] == (numb + 48)) {
                    validMas[v] = mas[i];
                    v++;
                    break;
                }
            }
        }

}

