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
