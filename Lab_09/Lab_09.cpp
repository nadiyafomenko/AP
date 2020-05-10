#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX 200  

typedef struct inform {      	     /* структура інформаційного поля */
    int AmountOfWords;
    char* mes;         	             /* вказівник на рядок повідомлення */
} INF;

typedef struct double_linked_list {    	  /* структура двонаправленого елемента списку */
    INF inf;
    struct double_linked_list* next, * prev;
} DLL;

typedef struct single_linked_list {     /* структура однонаправленого елемента списку */
    INF inf;
    struct single_linked_list* next;
} SLL;

DLL* DLL_head, * DLL_tail;  /* вказівники початку й кінця двонаправленого списку */
SLL* SSL_list;              /* вказівник початку однонаправленого списку */

//global functions
int InputData(INF* pinf);
void InsertElem(INF data);
void PrintList(const char* title, ...);
void CreateNewList(DLL* pold, char* keyWord);
void FreeList();

int main() {
    INF input;
    char keyWord[MAX];
    puts("\tEnter your strings (press Enter to stop):\n");
    while (InputData(&input) == 0) InsertElem(input);
    PrintList("\tYour List:\n");
    puts("Enter a keyword");
    gets_s(keyWord, MAX);
    CreateNewList(DLL_head, keyWord);
    PrintList("\tNew list", 'n');
    FreeList();
}

//local functions
int CountWords(char* mes);
void AddElem(DLL* pnew, DLL* pold);
void DeleteElement(DLL* pel);
int isSubstring(char* string, char* sub);

int InputData(INF* pinf)
{
    char buf[MAX];
    printf("\tYour message:   ");
    rewind(stdin);
    gets_s(buf, MAX);
    if (*buf) {
        pinf->mes = (char*)malloc(strlen(buf) + 1);	/* виділення ДП і */
        strcpy(pinf->mes, buf);	 /* запис рядка повідомлення */
        pinf->AmountOfWords = CountWords(buf);
        return 0;
    }
    else return 1;
}

int CountWords(char* mes) {
    int count = 1;
    for (int i = 0; i < MAX; i++) if (mes[i] == ' ') count++;
    return count;
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

void PrintList(const char* title, ...)
{
    va_list p;
    va_start(p, title);
    printf("\n\n%s\n", title);
    if (va_arg(p, char) == 'n') {
        SLL* pel = SSL_list;
        while (pel)
        {
            printf("\n%5d\t%s", pel->inf.AmountOfWords, pel->inf.mes);
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
    if (!isSubstring(pold->inf.mes, keyWord))
    {
        pnew->inf = pold->inf;
        pnew->next = SSL_list;
        SSL_list = pnew;
        DeleteElement(pold);
    }
    CreateNewList(pold->next, keyWord);
}

int isSubstring(char* string, char* sub) {
    if (!*string) return 1;
    int i = 0;
    if (*(sub + i) == *(string + i)) {
        return 0;
    }
    else isSubstring(string + 1, sub);
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
