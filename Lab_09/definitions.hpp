#define MAX_LEN 200  

typedef struct inform {      	      /* структура інформаційного поля */
    int index;
    char* mes;         	   /* вказівник на рядок повідомлення */
} DMINF;

typedef struct double_linked_list {    	  /* структура елемента списку */
    DMINF inf;
    struct double_linked_list* next, * prev;
} DLL;

typedef struct single_linked_list {
    DMINF inf;
    struct single_linked_list* next;
} SLL;

void InputData(DMINF* inf);             /* прототипи функцій */
void InsertElem(DMINF data);
void AddElem(DLL* pnew, DLL* pold);
void PrintList(const char*);
DLL* DeleteElem(DLL* pdel);
void FreeElemMemo(DLL* pel);
void FreeList(DLL* start);
int CountWords(char* mes);
void CreateNewList(DLL* pold, char* KeyWord);
void PrintNewList(const char* title);
int isSubstring(char* string, char* sub);

DLL* list_beg, * list_end;  /* вказівники початку й кінця списку */
SLL* SSL_list;