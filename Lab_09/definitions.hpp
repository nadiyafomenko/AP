#define MAX_LEN 200  

typedef struct inform {      	      /* ��������� �������������� ���� */
    int index;
    char* mes;         	   /* �������� �� ����� ����������� */
} DMINF;

typedef struct double_linked_list {    	  /* ��������� �������� ������ */
    DMINF inf;
    struct double_linked_list* next, * prev;
} DLL;

typedef struct single_linked_list {
    DMINF inf;
    struct single_linked_list* next;
} SLL;

void InputData(DMINF* inf);             /* ��������� ������� */
void InsertElem(DMINF data);
void AddElem(DLL* pnew, DLL* pold);
void PrintList(const char*);
void PrintReverse(DLL* last);
DLL* DeleteElem(DLL* pdel);
void FreeElemMemo(DLL* pel);
void DeleteAllOdd(void);
void FreeList(DLL* start);
int CountWords(char* mes);


DLL* list_beg, * list_end;  /* ��������� ������� � ���� ������ */