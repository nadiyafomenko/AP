#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "algorithms.hpp"

/* Функція  приєднання до списку елемента *pnew перед елементом *pold */
void AddElem(DLL* pnew, DLL* pold)
{
    if (pold == DLL_head) {	/* новий елемент cтає першим у списку */
        DLL_head->prev = pnew;
        pnew->next = DLL_head;
        pnew->prev = NULL;
        DLL_head = pnew;
        return;
    }
    if (pold != NULL) {	/* новий елемент вводиться у середину списку */
        pnew->next = pold;
        pnew->prev = pold->prev;
        pold->prev->next = pnew;
        pold->prev = pnew;
    }
    else {	/* новий елемент cтає останнім у списку */
        DLL_tail->next = pnew;
        pnew->prev = DLL_tail;
        pnew->next = NULL;
        DLL_tail = pnew;
    }
}

void InsertElem(INF data)
{
    DLL* pel, * pins;
    pel = (DLL*)malloc(sizeof(DLL));	/* виділення ДП */
    pel->inf = data;	                 /* заповнення поля даних */

    if (DLL_head == NULL) {	          /* якщо в списку ще не було елементів */
        pel->next = pel->prev = NULL;
        DLL_head = DLL_tail = pel;	   /* єдиний елемент списку */
        return;
    }

    pins = DLL_head;	       /* цикл пошуку позиції вставлення нового елемента */
    while (pins != NULL && data.AmountOfWords > pins->inf.AmountOfWords)
        pins = pins->next;
    AddElem(pel, pins);	/* приєднання нового елемента перед *pins */
}


void InputData()
{
    puts("\tEnter your strings (press Enter to stop):\n");
    while (true) {
        INF input;
        char buf[MAX];
        printf("\tYour message:   ");
        rewind(stdin);
        gets_s(buf, MAX);
        if (*buf) {
            input.mes = (char*)malloc(strlen(buf) + 1);	/* виділення ДП і */
            strcpy(input.mes, buf);	 /* запис рядка повідомлення */
            input.AmountOfWords = CountWords(buf);
            InsertElem(input);
        }
        else break;
    };
}

void InputDataFromFile() {
    INF input;
    char buf[MAX];
    FILE* file = fopen("messages.txt", "r");
    if (file == NULL) perror("Error opening file");
    while (fgets(buf, MAX + 1, file)) {
        if (*buf) {
            input.mes = (char*)malloc(strlen(buf) + 1);
            strcpy(input.mes, buf);
            input.AmountOfWords = CountWords(buf);
            InsertElem(input);
        }
    }
    fclose(file);
}

void DeleteElement(DLL* pel)
{
    if (pel->prev == NULL)
    {
        DLL_head = DLL_head->next;
        DLL_head->prev = NULL;
    }
    else if (pel->next == NULL)
    {
        DLL_tail = DLL_tail->prev;
        DLL_tail->next == NULL;
    }
    else
    {
        pel->next->prev = pel->prev;
        pel->prev->next = pel->next;
    }
}

void PrintList(const char* title, ...)
{
    va_list p;
    va_start(p, title);
    printf("\n%s\n", title);
    if (va_arg(p, char) == 'n') {
        SLL* pel = SSL_list;
        while (pel)
        {
            printf("%5d\t%s", pel->inf.AmountOfWords, pel->inf.mes);
            pel = pel->next;
        }
    }
    else {
        DLL* pel = DLL_head;
        while (pel) {
            printf("\n%5d\t%s", pel->inf.AmountOfWords, pel->inf.mes);
            pel = pel->next;
        }
    }
    va_end(p);
    printf("\n\n");
}

void CreateNewList(DLL* pold, char* keyWord)
{
    if (pold == NULL) return;
    SLL* pnew;
    pnew = (SLL*)malloc(sizeof(SLL));
    if (isSubstring(pold->inf.mes, keyWord) != 1)
    {
        pnew->inf = pold->inf;
        pnew->next = SSL_list;
        SSL_list = pnew;
        DeleteElement(pold);
    }
    CreateNewList(pold->next, keyWord);
}


void FreeList()
{
    SLL* pel = SSL_list;
    while (pel != NULL)
    {
        SSL_list = SSL_list->next;
        free(pel->inf.mes);
        free(pel);
        pel = SSL_list;
    }
}
