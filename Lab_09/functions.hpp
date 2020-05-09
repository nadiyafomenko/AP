
/* Функція введення даних елемента списку */
void InputData(DMINF* pinf)
{
    char buf[MAX_LEN];
    printf("\tПовідомлення:   ");
    rewind(stdin);
    gets_s(buf, MAX_LEN);
    pinf->mes = (char*)malloc(strlen(buf) + 1);	/* виділення ДП і */
    strcpy(pinf->mes, buf);	 /* запис рядка повідомлення */
    pinf->index = CountWords(buf);
}

int CountWords(char* mes) {
    int count = 1;
    for (int i = 0; i < MAX_LEN; i++) if (mes[i] == ' ') count++;
    return count;
}
/* Функція приєднання елемента до списку за порядком зростання індексів */
void InsertElem(DMINF data)
{
    DLL* pel, * pins;
    pel = (DLL*)malloc(sizeof(DLL));	/* виділення ДП */
    pel->inf = data;	                 /* заповнення поля даних */

    if (list_beg == NULL) {	          /* якщо в списку ще не було елементів */
        pel->next = pel->prev = NULL;
        list_beg = list_end = pel;	   /* єдиний елемент списку */
        return;
    }

    pins = list_beg;	       /* цикл пошуку позиції вставлення нового елемента */
    while (pins != NULL && data.index > pins->inf.index)
        pins = pins->next;
    AddElem(pel, pins);	/* приєднання нового елемента перед *pins */
}

/* Функція  приєднання до списку елемента *pnew перед елементом *pold */
void AddElem(DLL* pnew, DLL* pold)
{
    if (pold == list_beg) {	/* новий елемент cтає першим у списку */
        list_beg->prev = pnew;
        pnew->next = list_beg;
        pnew->prev = NULL;
        list_beg = pnew;
        return;
    }
    if (pold != NULL) {	/* новий елемент вводиться у середину списку */
        pnew->next = pold;
        pnew->prev = pold->prev;
        pold->prev->next = pnew;
        pold->prev = pnew;
    }
    else {	/* новий елемент cтає останнім у списку */
        list_end->next = pnew;
        pnew->prev = list_end;
        pnew->next = NULL;
        list_end = pnew;
    }
}

/* Функція виведення даних списку в прямому порядку */
void PrintList(const char* title)
{
    printf("\n\n\t\t%s\n", title);
    DLL* pel = list_beg;
    while (pel != NULL) {
        printf("\n%5d   %s", pel->inf.index, pel->inf.mes);
        pel = pel->next;
    }
    printf("\n\n");
}


/* Функція видалення елемента списку (повертає вказівник на наступний за видаленим елемент) */
DLL* DeleteElem(DLL* pdel)
{
    if (pdel == list_beg) {	/* видалення першого елемента списку */
        list_beg = list_beg->next;
        list_beg->prev = NULL;
        FreeElemMemo(pdel);
        return list_beg;
    }
    if (pdel == list_end) {	/* видалення останнього елемента списку */
        list_end = list_end->prev;
        list_end->next = NULL;
        FreeElemMemo(pdel);
        return NULL;
    }
    else {	/* видалення серединного елемента списку */
        DLL* pnext;
        pdel->next->prev = pdel->prev;
        pnext = pdel->prev->next = pdel->next;
        FreeElemMemo(pdel);
        return pnext;
    }
}


/* Рекурсивна функція витирання списку */
void FreeList(DLL* start)
{
    if (start == NULL)  return;
    list_beg = start->next;
    FreeElemMemo(start);	/* витирання початкового елемента */
    FreeList(list_beg);	/* рекурсивне продовження */
}

/* Функція звільнення ДП, зайнятої елементом списку */
void FreeElemMemo(DLL* pel)
{
    free(pel->inf.mes);	/* витирання рядка повідомлення */
    free(pel); 	       /* витирання елемента списку    */
}
