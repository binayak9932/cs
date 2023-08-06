#include <stdio.h>
#include <stdlib.h>

int getHighestExponent(int *poly, int size) {
    int highest_exponent = 0;
    for (int i = 1; i < size; i += 2) {
        if (poly[i] > highest_exponent) {
            highest_exponent = poly[i];
        }
    }
    return highest_exponent;
}


void addPolynomials(int *poly1, int *poly2, int *result_poly) {
    int size1 = poly1[0];
    int size2 = poly2[0];
    int i = 1, j = 1, k = 1;

    while (i < size1 && j < size2) {
        if (poly1[i + 1] == poly2[j + 1]) {
            result_poly[k] = poly1[i] + poly2[j];
            result_poly[k + 1] = poly1[i + 1];
            i += 2;
            j += 2;
        } else if (poly1[i + 1] > poly2[j + 1]) {
            result_poly[k] = poly1[i];
            result_poly[k + 1] = poly1[i + 1];
            i += 2;
        } else {
            result_poly[k] = poly2[j];
            result_poly[k + 1] = poly2[j + 1];
            j += 2;
        }
        k += 2;
    }


    while (i < size1) {
        result_poly[k] = poly1[i];
        result_poly[k + 1] = poly1[i + 1];
        i += 2;
        k += 2;
    }


    while (j < size2) {
        result_poly[k] = poly2[j];
        result_poly[k + 1] = poly2[j + 1];
        j += 2;
        k += 2;
    }


    result_poly[0] = k;
}

int main() {
    int size1, size2;
    int *poly1, *poly2, *result_poly;


    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &size1);


    poly1 = (int *)malloc((2 * size1 + 1) * sizeof(int));


    printf("Enter the coefficients and exponents for the first polynomial:\n");
    for (int i = 1; i <= 2 * size1; i += 2) {
        printf("Coefficient %d: ", i / 2 + 1);
        scanf("%d", &poly1[i]);
        printf("Exponent %d: ", i / 2 + 1);
        scanf("%d", &poly1[i + 1]);
    }
    poly1[0] = 2 * size1;


    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &size2);

    poly2 = (int *)malloc((2 * size2 + 1) * sizeof(int));


    printf("Enter the coefficients and exponents for the second polynomial:\n");
    for (int i = 1; i <= 2 * size2; i += 2) {
        printf("Coefficient %d: ", i / 2 + 1);
        scanf("%d", &poly2[i]);
        printf("Exponent %d: ", i / 2 + 1);
        scanf("%d", &poly2[i + 1]);
    }
    poly2[0] = 2 * size2;


    int size_result = getHighestExponent(poly1, 2 * size1 + 1) + getHighestExponent(poly2, 2 * size2 + 1) + 2;


    result_poly = (int *)malloc(size_result * sizeof(int));


    addPolynomials(poly1, poly2, result_poly);


    printf("\nResultant Polynomial:\n");
    for (int i = 1; i < result_poly[0]; i += 2) {
        printf("%dx^%d ", result_poly[i], result_poly[i + 1]);
        if (i < result_poly[0] - 2) {
            printf("+ ");
        }
    }
    printf("\n");


    free(poly1);
    free(poly2);
    free(result_poly);

    return 0;
}
