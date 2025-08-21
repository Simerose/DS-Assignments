#include <stdio.h>
int main()
{
    int m, n, i, j;
    printf("Enter the dimensions of the matrix: ");
    scanf("%d%d", &m, &n);

    int matrix[50][50];

 printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

//Sum of rows
for (i = 0; i < m; i++) {
        int sumrow = 0;
        for (j = 0; j < n; j++) {
            sumrow += matrix[i][j];
        }
        printf("Sum of Row %d = %d\n", i + 1, sumrow);
    }
//sum of columns
    for (j = 0; j < n; j++) {
        int sumcol = 0;
        for (i = 0; i < m; i++) {
            sumcol += matrix[i][j];
        }
        printf("Sum of Column %d = %d\n", j + 1, sumcol);
    }

    return 0;
}

