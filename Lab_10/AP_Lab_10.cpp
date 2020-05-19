﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct inform {      	     /* структура інформаційного поля */
    int year;
    char* event;         	             /* вказівник на рядок повідомлення */
} INF;

typedef struct node {    	  /* структура двонаправленого елемента списку */
    INF inf;
    struct node* left, * right;
} NODE;

NODE* root;

NODE* CreateNode(INF* inform);
void AddNodeIter(NODE* pnew);
int ReadNodesFromFile();
void Print(NODE* root);
int TreeHeight(NODE* proot);
void treeBalanced(NODE* proot);
void DeleteAllNodes();
void DeleteLeaves();

int main()
{
    ReadNodesFromFile();
    Print(root);

    printf("\nTree height: %i\n", TreeHeight(root));
    if (TreeHeight(root->left) != TreeHeight(root->right))
        treeBalanced(root);
    else
        printf("Tree is balanced!\n");

    DeleteAllNodes();
    root = NULL;
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
    file = fopen("TreeData.txt", "r");

    while (fscanf(file,"%s %d", buf, &year) != EOF)
    {
        inform.event = buf;
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
        printf("Year: %d\n", root->inf.year);
    Print(root->right);
}

int TreeHeight(NODE* proot)
{
    int lh, rh;
    if (proot == NULL) return 0;
    lh = TreeHeight(proot->left);
    rh = TreeHeight(proot->right);
    return lh > rh ? lh + 1 : rh + 1;
}

void treeBalanced(NODE* proot)
{
    int rootdif = TreeHeight(proot->left) - TreeHeight(proot->right);
    if (rootdif >= 1)
    {
        printf("Node [%i] is not balanced!\n", proot->inf.year);
        treeBalanced(proot->left);
    }
    else if (rootdif <= -1)
    {
        printf("Node [%i] is not balanced!\n", proot->inf.year);
        treeBalanced(proot->right);
    }
    else
    {
        return;
    }
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

void DeleteLeaves() {
    NODE* node = root;
    NODE* next; 
    while (node != NULL) {
        if (node->left != NULL) {
            next = node->left;
            if (node->right == NULL || node->left == NULL)
                free(node);
        }
        else
            if (node->right != NULL)
                next = node->right;
                if (node->right == NULL || node->left == NULL)
                    free(node);
    }
}
