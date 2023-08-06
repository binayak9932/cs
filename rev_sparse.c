#include <stdio.h>

int main() {
    int rows,cols,n_zero,row[20], col[20], val[20];;
    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of non-zero elements in the sparse matrix: ");
    scanf("%d", &n_zero);
    printf("Enter the sparse matrix (Triple format - Row, Column, Value):\n");
    for (int i = 0; i < n_zero; i++) {
        printf("Element %d:\n", i + 1);
        printf("Row: ");
        scanf("%d", &row[i]);
        printf("Column: ");
        scanf("%d", &col[i]);
        printf("Value: ");
        scanf("%d", &val[i]);
    }
    int mat[20][20] = {0};
    for (int i = 0; i < n_zero; i++) {
        mat[row[i]][col[i]] = val[i];
    }
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
