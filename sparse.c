#include <stdio.h>
#include  <stdlib.h>

int main() {
    int arr[10][10], mat[20][3], i, j, k, l, m, row, col, c = 0, tot = 0;
    printf("Enter the number of rows of the matrix\n");
    scanf("%d", &row);
    printf("Enter the number of columns of the matrix\n");
    scanf("%d", &col);
    printf("Enter the elements of the matrix\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The matrix is\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", arr[i][j]);
            if (arr[i][j] != 0) {
                c += 1;
            }
        }
        printf("\n");
    }
    tot = row * col;
    if ((c * 3) <= tot) {
        printf("The  matrix is an efficient  sparse matrix\n");
        k = 1;
        mat[0][0] = row;
        mat[0][1] = col;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (arr[i][j] != 0) {
                    mat[k][0] = i;
                    mat[k][1] = j;
                    mat[k][2] = arr[i][j];
                    k++;
                }
            }
        }
        mat[0][2] = k - 1;


        m = mat[0][2];
        printf("The sparse matrix representation is\n");
        for (i = 0; i <= m; i++) {
            printf("%d\t %d\t %d\t \n", mat[i][0], mat[i][1], mat[i][2]);

        }
    } else {
        printf("The matrix is not an efficient sparse matrix\n");
        return 0;
    }

}


