#include <stdio.h>
#include <math.h>

#define MAX_VARS 10
#define MAX_ITER 1000

void gauss_seidel(float A[MAX_VARS][MAX_VARS], float B[MAX_VARS], float X[MAX_VARS], int n, float tol) {
    int i, j, k;
    float newX[MAX_VARS], error, sum;

    for (k = 0; k < MAX_ITER; k++) {
        error = 0.0f;
        for (i = 0; i < n; i++) {
            sum = 0.0f;
            for (j = 0; j < n; j++) {
                if (j != i)
                    sum += A[i][j] * X[j];
            }
            newX[i] = (B[i] - sum) / A[i][i];
            error += fabsf(newX[i] - X[i]);
            X[i] = newX[i];
        }
        if (error < tol) {
            printf("Converged after %d iterations\n", k + 1);
            break;
        }
    }

    if (k == MAX_ITER)
        printf("Did not converge after %d iterations\n", MAX_ITER);
}

int main() {
    int n, i, j;
    float A[MAX_VARS][MAX_VARS], B[MAX_VARS], X[MAX_VARS], tol;

    printf("Enter the number of variables (maximum %d): ", MAX_VARS);
    scanf("%d", &n);

    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter the constants on the right-hand side:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &B[i]);

    printf("Enter the tolerance limit: ");
    scanf("%f", &tol);

    for (i = 0; i < n; i++)
        X[i] = 0.0f;

    gauss_seidel(A, B, X, n, tol);

    printf("Solution:\n");
    for (i = 0; i < n; i++)
        printf("X[%d] = %f\n", i, X[i]);

    return 0;
}
