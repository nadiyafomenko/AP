#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 5


double** CreateMatrix();
void DeleteMatrix(double** matrix);
void Print(double* matrix[]);
double** Transposition(double** matrix);
double** ReadMatrixFromFile();

int size = 0;

int main()
{
    int option=0;
    double** matrix;
    puts("Choose the option:\n1. Enter matrix from keyboard\n2. Read from file\n");
    scanf_s("%d", &option);
    switch(option) {
        case 1: {
            matrix = CreateMatrix();
            break;
        }
        case 2: {
            matrix = ReadMatrixFromFile();
            break;
        }
        default: puts("wrong input");
    }
    Print(matrix);
    puts("Transported matrix:\n");
    double** transported = Transposition(matrix);
    Print(transported);
    DeleteMatrix(matrix);
    DeleteMatrix(transported);
}

double** CreateMatrix()
{
    double** m;
    puts("Enter matrix size:\t");
    scanf_s("%d", &size);

    m = (double**)malloc(size * sizeof(double*));

    for (int i = 0; i < size; i++) {
        m[i] = (double*)malloc(size * sizeof(double));
            for (int j = 0; j < size; j++)
            {
                printf("a[%d][%d] = ", i, j);
                scanf_s("%lf", &m[i][j]);    
            }
        }
    return m;
}


double** ReadMatrixFromFile()
{
    FILE* file = fopen("D:\\matrix.txt", "r");

    if (file == NULL)
    {
        printf("could not open\n");
        return NULL;
    }
    
    double** m = (double**)malloc(MAX*sizeof(double*));
    for (int i = 0; i < 2; i++) {
        if (m) {
            *m = (double*)malloc(MAX * sizeof(double));
            for (int j = 0; j < MAX; j++) {
                fscanf_s(file, "%lf", &m[i][j]);
            }
            puts("\n");
        }
    }
    return m;
}
//
//double** mtrx() {
//    FILE* arr;
//    double** k = { 0 };
//    arr = fopen("D:\\matrix.txt", "r");
//    int i, j;
//
//
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 3; j++)
//        {
//            double num = fscanf(arr, "%lf%*[^\n]", &k[i][j]);
//            printf("%f\n", num);
//        }
//    }
//    return k;
//}
//
void DeleteMatrix(double** matrix) {
    for (int i = 0; i < size; i++) free(matrix[i]);
    free(matrix);
}

void Print(double* matrix[])
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            printf("%lf\t", matrix[i][j]); 
        }
        printf("\n");
    }
}

double** Transposition(double** matrix) {
    double** tmp = (double**)malloc(_MAX_PATH);
    for (int i = 0; i < size; ++i) tmp[i] = (double*)malloc(_MAX_PATH);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) tmp[i][j] = matrix[j][i];
    return tmp;
}
