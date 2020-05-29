#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "const.hpp"
#include "listFunc.hpp"


int main() {

    int option = 0;
    puts("Choose the option:\n1. Enter messages from keyboard\n2. Read from file\n");
    scanf_s("%d", &option);

    switch (option) {
        case 1: {

            InputData();
            break;
        }
        case 2: {
            InputDataFromFile();
            break;
        }
        default: {
            puts("wrong option"); 
            return 1;
        }
    }
    
    PrintList("Your List:");

    char keyWord[MAX];
    puts("Enter a keyword");
    rewind(stdin);
    gets_s(keyWord, MAX);

    CreateNewList(DLL_head,keyWord);

    PrintList("New list", 'n');

    FreeList();

    return 0;
}
