#include <stdio.h>

struct Sparse {
    int row;
    int col;
    int value;
};

int main() {
    int m, n, num1, num2, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    struct Sparse mat1[100], mat2[100], result[200];

    //  Matrix 1
    printf("Enter number of non-zero elements in Matrix 1: ");
    scanf("%d", &num1);
    printf("Enter row, column, value for Matrix 1:\n");
    for (i = 0; i < num1; i++)
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);

    // Matrix 2
    printf("Enter number of non-zero elements in Matrix 2: ");
    scanf("%d", &num2);
    printf("Enter row, column, value for Matrix 2:\n");
    for (i = 0; i < num2; i++)
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);

    // Transpose Matrix 1 
    printf("\nTranspose of Matrix 1:\n");
    for (i = 0; i < n; i++) { 
        for (j = 0; j < num1; j++) {
            if (mat1[j].col == i)
                printf("(%d,%d,%d) ", mat1[j].col, mat1[j].row, mat1[j].value);
        }
    }
    printf("\n");

    //  Addition 
    printf("\nAddition of Matrix 1 and Matrix 2:\n");
    int k = 0, p = 0, q = 0;
    while (p < num1 && q < num2) {
        if (mat1[p].row < mat2[q].row || 
           (mat1[p].row == mat2[q].row && mat1[p].col < mat2[q].col))
            result[k++] = mat1[p++];
        else if (mat1[p].row > mat2[q].row || 
                (mat1[p].row == mat2[q].row && mat1[p].col > mat2[q].col))
            result[k++] = mat2[q++];
        else { 
            result[k] = mat1[p];
            result[k++].value = mat1[p++].value + mat2[q++].value;
        }
    }
    while (p < num1) result[k++] = mat1[p++];
    while (q < num2) result[k++] = mat2[q++];

    for (i = 0; i < k; i++)
        printf("(%d,%d,%d) ", result[i].row, result[i].col, result[i].value);
    printf("\n");

    //  Multiplication
    int A[10][10] = {0}, B[10][10] = {0}, C[10][10] = {0};
    for (i = 0; i < num1; i++) A[mat1[i].row][mat1[i].col] = mat1[i].value;
    for (i = 0; i < num2; i++) B[mat2[i].row][mat2[i].col] = mat2[i].value;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            for (int l = 0; l < n; l++)
                C[i][j] += A[i][l] * B[l][j];

    printf("\nMultiplication Result:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}

