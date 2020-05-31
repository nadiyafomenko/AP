#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct inform {
    int year;
    char* event;
} INF;

typedef struct node
{
    INF inf;
    struct node* left;
    struct node* right;
} NODE;

NODE* root = 0;

int ReadNodesFromFile();
void AddElem(INF inf, NODE** leaf);
void destroy_tree(NODE* leaf);
void Print(NODE* root);
void PrintInRange(NODE* root, int from, int to);
NODE* deleteLeaves(NODE* root);


int main() {

    if (ReadNodesFromFile() == 1) return 1;
    Print(root);
    puts("\nPrinting in range\n");
    PrintInRange(root, 10, 2000);
    destroy_tree(root);
    puts("\nTree destroyed");

}

void destroy_tree(NODE* leaf)
{
    if (leaf != 0)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        free(leaf);
    }
}

void AddElem(INF inf, NODE** leaf)
{
    if (*leaf == 0)
    {
        *leaf = (NODE*)malloc(sizeof(NODE));
        (*leaf)->inf.year = inf.year;
        (*leaf)->inf.event = inf.event;
        (*leaf)->left = 0;
        (*leaf)->right = 0;
    }
    else if (inf.year < (*leaf)->inf.year)
    {
        AddElem(inf, &(*leaf)->left);
    }
    else if (inf.year > (*leaf)->inf.year)
    {
        AddElem(inf, &(*leaf)->right);
    }
}

int ReadNodesFromFile()
{
    FILE* file;

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
        puts("First file is opened");
        file = fopen("TreeData_first.txt", "r");
    }
    }

    INF* inform;
    NODE* tempNode;
    char buf[100];
    int year = 0;

    tempNode = (NODE*)malloc(sizeof(NODE));
    inform = (INF*)malloc(sizeof(INF));

    while (fscanf(file, "%s %d", buf, &year) != EOF)
    {

        inform->event = (char*)malloc(1000000);
        strcpy(inform->event, buf);
        inform->year = year;
        AddElem(*inform, &root);
    }
    return 0;
}

void Print(NODE* root)
{
    if (root == 0)
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
    if (root->inf.year > from&& root->inf.year < to) {
        printf("Year: %d\tEvent: %s\n", root->inf.year, root->inf.event);
    }

    PrintInRange(root->right, from, to);
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