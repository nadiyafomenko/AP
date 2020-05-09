#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definitions.hpp"
#include "functions.hpp"
 
int main(void)
{
    system("chcp 1251");

    DMINF input;
    char p = 'y';
    char KeyWord[MAX_LEN];

    puts("\n\t\t Вхідні дані:");
    do {
        InputData(&input);
        InsertElem(input);

        puts("\tВвести ще один елемент? (y/n):");
        scanf_s("%c", &p);
    } while (p == 'y');  

   
    PrintList("Сформований список");
    puts("\n\t\t Ключове слово:");
    rewind(stdin);
    gets_s(KeyWord, MAX_LEN);         
    return 0;
}


