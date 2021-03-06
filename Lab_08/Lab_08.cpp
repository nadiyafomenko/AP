#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double** CreateMatrix();
double** ReadMatrixFromFile();
double** Transposition(double** matrix);

void Print(double* matrix[], int size);
int DeleteRow(double** matrix, int size);

double Sum(double* mas);

void DeleteMatrix(double** matrix, int);

int size;       //розмір введеної матриці
#define MAX 5    // розмір матриці з файлу

int main() {

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
    Print(matrix, size);
    puts("\nTransported matrix:");
    double** transposed = Transposition(matrix);
    Print(transposed, size);
    int size_tr = DeleteRow(transposed, size); 
    puts("\n");
    Print(transposed, size_tr);
    DeleteMatrix(transposed, size_tr);

    DeleteMatrix(matrix, size);
}

double** CreateMatrix() {
    double** m;
    puts("Enter matrix size:\t");
    scanf_s("%d", &size);

    m = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++) {
        m[i] = (double*)calloc(size + 1, sizeof(double));
            for (int j = 0; j < size; j++)
            {
                printf("a[%d][%d] = ", i, j);
                scanf_s("%lf", &m[i][j]);    
            }
        }
    return m;
}

double** ReadMatrixFromFile() {
    size = MAX;
    FILE* file = fopen("D:\\matrix.txt", "r");
    double** m = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; ++i) {
        m[i] = (double*)calloc(size, sizeof(double));
        for (int j = 0; j < size; ++j)
        {
            int readCount = fscanf(file, "%lf", &m[i][j]);
            if (readCount != 1)
            {
                printf("Error reading file on element %d : %d!\n", i, j);
                return 0;
            }
        }
    }
    return m;
}

int DeleteRow(double** matrix, int size) {
    double max[2] = { 0 };
    max[0] = Sum(matrix[0]);
    max[1] = 0;
    for (int j = 0; j < size; j++) {
        if (Sum(matrix[j]) > max[0]) {
            max[0] = Sum(matrix[j]);
            max[1] = j;
        }
    }
    free(*(matrix + (int)max[1]));
    for (int i = max[1]; i < size - 1; i++) {
        matrix[i] = matrix[i + 1];
    }

    return size - 1;
    //puts("\nMatrix with deleted max row:");
    //for (int i = 0; i < size; i++) {
    //    if (i != max[1]) {
    //        for (int j = 0; j < size; j++) {
    //            printf("%lf\t", matrix[i][j]);
    //        }
    //    } else continue;
   
    //    printf("\n");
    //} 
}

double Sum(double* mas) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += mas[i];
    }
    return sum;
}

void DeleteMatrix(double** matrix, int size)
{
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void Print(double* matrix[], int size) {
    for (int i = 0; i < size; i++)  {
        for (int j = 0; j < size; j++) {
            printf("%lf\t", matrix[i][j]); 
        }
        printf("\n");
    }
}

double** Transposition(double** matrix) {
    double** transposed = (double**)malloc(_MAX_PATH);
    for (int i = 0; i < size; ++i) {
        transposed[i] = (double*)malloc(_MAX_PATH);
        for (int j = 0; j < size; ++j) {
            transposed[i][j] = matrix[j][i];
        }    
    }
    return transposed;
}
