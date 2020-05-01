#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double** CreateMatrix();
void DeleteMatrix(double** matrix, int k);
void Print(double* matrix[]);
double** Transposition(double** matrix);
double** ReadMatrixFromFile();
void DeleteRow(double** matrix);
void bubbleSort(double** mas);

int size = 0;
#define MAX 5

int main()
{
    int option = 0;
    double** matrix = { 0 };
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
    DeleteRow(transported);
    Print(transported);
    DeleteMatrix(matrix,size);
}

double** CreateMatrix()
{
    double** m;
    puts("Enter matrix size:\t");
    scanf_s("%d", &size);

    m = (double**)calloc(size, sizeof(double*));
    if (!m) return NULL;
    for (int i = 0; i < size; i++) {
        m[i] = (double*)calloc(size + 1, sizeof(double));
        if (!*(m + i)) {
            DeleteMatrix(m,i);
            return NULL;
        }
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

void DeleteRow(double** matrix) {
    double** sum = (double**)calloc(size,sizeof(double));
    for (int j = 0; j < size; j++) {
        sum[j] = (double*)calloc(size, sizeof(double));
        for (int i = 0; i < size; i++) {
            sum[j][1] = j;
            sum[j][0] += matrix[j][i];  
        }
    }
    bubbleSort(sum);
    const int k = sum[0][1];
    free(matrix[k]);
}

void bubbleSort(double** mas)
{
    double temp;
        for (int i = 0; i < size; i++)
        {
            if (mas[i] < mas[i + 1] )
            {
                temp = mas[i + 1][0];
                mas[i + 1][0] = mas[i][0];
                mas[i][0] = temp;
            }
        }
   
}

void DeleteMatrix(double** matrix, int k) {
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
