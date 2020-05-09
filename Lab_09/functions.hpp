
/* ������� �������� ����� �������� ������ */
void InputData(DMINF* pinf)
{
    char buf[MAX_LEN];
    printf("\t�����������:   ");
    rewind(stdin);
    gets_s(buf, MAX_LEN);
    pinf->mes = (char*)malloc(strlen(buf) + 1);	/* �������� �� � */
    strcpy(pinf->mes, buf);	 /* ����� ����� ����������� */
    pinf->index = CountWords(buf);
}

int CountWords(char* mes) {
    int count = 1;
    for (int i = 0; i < MAX_LEN; i++) if (mes[i] == ' ') count++;
    return count;
}
/* ������� ��������� �������� �� ������ �� �������� ��������� ������� */
void InsertElem(DMINF data)
{
    DLL* pel, * pins;
    pel = (DLL*)malloc(sizeof(DLL));	/* �������� �� */
    pel->inf = data;	                 /* ���������� ���� ����� */

    if (list_beg == NULL) {	          /* ���� � ������ �� �� ���� �������� */
        pel->next = pel->prev = NULL;
        list_beg = list_end = pel;	   /* ������ ������� ������ */
        return;
    }

    pins = list_beg;	       /* ���� ������ ������� ���������� ������ �������� */
    while (pins != NULL && data.index > pins->inf.index)
        pins = pins->next;
    AddElem(pel, pins);	/* ��������� ������ �������� ����� *pins */
}

/* �������  ��������� �� ������ �������� *pnew ����� ��������� *pold */
void AddElem(DLL* pnew, DLL* pold)
{
    if (pold == list_beg) {	/* ����� ������� c�� ������ � ������ */
        list_beg->prev = pnew;
        pnew->next = list_beg;
        pnew->prev = NULL;
        list_beg = pnew;
        return;
    }
    if (pold != NULL) {	/* ����� ������� ��������� � �������� ������ */
        pnew->next = pold;
        pnew->prev = pold->prev;
        pold->prev->next = pnew;
        pold->prev = pnew;
    }
    else {	/* ����� ������� c�� ������� � ������ */
        list_end->next = pnew;
        pnew->prev = list_end;
        pnew->next = NULL;
        list_end = pnew;
    }
}

/* ������� ��������� ����� ������ � ������� ������� */
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


/* ������� ��������� �������� ������ (������� �������� �� ��������� �� ��������� �������) */
DLL* DeleteElem(DLL* pdel)
{
    if (pdel == list_beg) {	/* ��������� ������� �������� ������ */
        list_beg = list_beg->next;
        list_beg->prev = NULL;
        FreeElemMemo(pdel);
        return list_beg;
    }
    if (pdel == list_end) {	/* ��������� ���������� �������� ������ */
        list_end = list_end->prev;
        list_end->next = NULL;
        FreeElemMemo(pdel);
        return NULL;
    }
    else {	/* ��������� ����������� �������� ������ */
        DLL* pnext;
        pdel->next->prev = pdel->prev;
        pnext = pdel->prev->next = pdel->next;
        FreeElemMemo(pdel);
        return pnext;
    }
}


/* ���������� ������� ��������� ������ */
void FreeList(DLL* start)
{
    if (start == NULL)  return;
    list_beg = start->next;
    FreeElemMemo(start);	/* ��������� ����������� �������� */
    FreeList(list_beg);	/* ���������� ����������� */
}

/* ������� ��������� ��, ������� ��������� ������ */
void FreeElemMemo(DLL* pel)
{
    free(pel->inf.mes);	/* ��������� ����� ����������� */
    free(pel); 	       /* ��������� �������� ������    */
}
