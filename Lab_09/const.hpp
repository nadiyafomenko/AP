#define MAX 200  

typedef struct inform {      	     /* ��������� �������������� ���� */
    int AmountOfWords;
    char* mes;         	             /* �������� �� ����� ����������� */
} INF;

typedef struct double_linked_list {    	  /* ��������� ��������������� �������� ������ */
    INF inf;
    struct double_linked_list* next, * prev;
} DLL;

typedef struct single_linked_list {     /* ��������� ���������������� �������� ������ */
    INF inf;
    struct single_linked_list* next;
} SLL;

DLL* DLL_head, * DLL_tail;  /* ��������� ������� � ���� ��������������� ������ */
SLL* SSL_list;              /* �������� ������� ���������������� ������ */
