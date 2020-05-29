#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct inform {      	        /* структура інформаційного поля */
    int year;
    char* event;         	            /* вказівник на рядок повідомлення */
} INF;

typedef struct node {    	            /* структура двонаправленого елемента списку */
    INF inf;
    struct node* left, * right;
} NODE;

NODE* root;

NODE* CreateNode(INF* inform);
void AddNodeIter(NODE* pnew);
int ReadNodesFromFile();
void Print(NODE* root);
void PrintInRange(NODE* root, int from, int to);
void DeleteAllNodes();

NODE* deleteLeaves(NODE* root);

int main()
{
    if (ReadNodesFromFile() == 1 ) return 1;
    Print(root);

    int yearFrom = 0, yearTo = 0;

    puts("\nEnter year range:");
    puts("\nFrom:");
    scanf_s("%d", &yearFrom);
    puts("To:");
    scanf_s("%d", &yearTo);
    puts("\nTree in your range:\n");
    PrintInRange(root, yearFrom, yearTo);           //роздрук дерева в заданому діапазоні


    puts("\nTree after deleting leaves:\n");
    deleteLeaves(root);                             //видалення листків дерева
    Print(root);


    DeleteAllNodes();
    root = NULL;

    return 0;
}

NODE* CreateNode(INF* inform)
{
    NODE* tempNode;
    tempNode = (NODE*)malloc(sizeof(NODE));
    tempNode->inf = *inform;
    tempNode->left = tempNode->right = NULL;
    return tempNode;
}

int ReadNodesFromFile()
{
    FILE* file;
    INF inform;
    NODE* tempNode;
    char buf[MAX];
    int year = 0;

    tempNode = (NODE*)malloc(sizeof(NODE));

    int option = 0;
    puts("Change file:\n1.TreeData_first.txt\n2.TreeData_second.txt");
    scanf_s("%d", &option);
    switch (option) {
    case 1: {
        file = fopen("TreeData_first.txt", "r");
        break;
    }
    case 2: {
        file = fopen("TreeData_second.txt", "r");
        break;
    }
    default: {
        puts("No such option");
        return 1; 
    }
    }

    while (fscanf(file,"%s %d", buf, &year) != EOF)
    {
        inform.event = (char*)malloc(MAX);
        strcpy(inform.event, buf);
        inform.year = year;
        tempNode = CreateNode(&inform);
        AddNodeIter(tempNode);
    }
    return 0;
}

void AddNodeIter(NODE* node)
{
    if (root == NULL) {
        root = node;
        return;
    }
    NODE* tempNode = root;
    do {
        if (node->inf.year == tempNode->inf.year) {
            free(node);    
            return;
        }
        if (node->inf.year > tempNode->inf.year)
            if (tempNode->right == NULL) {
                tempNode->right = node;    /* новий елемент стає правим листком */
                return;
            }
            else
                tempNode = tempNode->right;
        else
            if (tempNode->left == NULL) {
                tempNode->left = node;      /* новий елемент стає лівим листком */
                return;
            }
            else
                tempNode = tempNode->left;

    } while (true);

}

void Print(NODE* root)
{
    if (root == NULL)
        return;
    Print(root->left);
    if (root->inf.year)
        printf("Year: %d\t Event: %s\n", root->inf.year, root->inf.event);
    Print(root->right);
}

void PrintInRange(NODE* root, int from, int to)
{
    if (root == NULL)
        return;
    PrintInRange(root->left, from, to);
    if (root->inf.year > from && root->inf.year < to) {
        printf("Year: %d\t Event: %s\n", root->inf.year, root->inf.event);
    }
            
    PrintInRange(root->right, from, to);
}

int TreeHeight(NODE* proot)
{
    int lh, rh;
    if (proot == NULL) return 0;
    lh = TreeHeight(proot->left);
    rh = TreeHeight(proot->right);
    return lh > rh ? lh + 1 : rh + 1;
}

void DeleteAllNodes()
{
    NODE* node = root, * next;
    NODE** stack;          
    stack = (NODE**)calloc(TreeHeight(root), sizeof(NODE*));
    int n = 0;                
    while (node != NULL) {
        if (node->left != NULL) {
            next = node->left;
            if (node->right != NULL)
                stack[++n] = node->right;
        }
        else
            if (node->right != NULL)
                next = node->right;
            else
                next = stack[n--];
        free(node);
        node = next;
    }
    free(stack);
    puts("\nTree Deleted\n");
}

NODE* deleteLeaves(NODE* root)
{
    if (root == NULL)
        return nullptr;
    root->left = deleteLeaves(root->left);
    root->right = deleteLeaves(root->right);

    if (root->left == NULL && root->right == NULL) {

        return NULL;
    }
    return root;
}