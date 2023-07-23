#include <stdio.h>
#include <stdlib.h>
int main (){
    int **mat1,**mat2,**mat,row,col,i,j,k;
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d%d",&row,&col);
    mat=(int **)malloc(row*sizeof(int *));
    for(i=0;i<row;i++)
        mat[i]=(int *)malloc(col*sizeof(int));

    mat1=(int **)malloc(row*sizeof(int *));
    for(i=0;i<row;i++)
        mat1[i]=(int *)malloc(col*sizeof(int));
    printf("Enter the elements of matrix: ");
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",*(mat1+i)+j);

    mat2=(int **)malloc(row*sizeof(int *));
    for(i=0;i<row;i++)
        mat2[i]=(int *)malloc(col*sizeof(int));
    printf("Enter the elements of matrix: ");
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",*(mat2+i)+j);

    for(i=0;i<row;i++){

        for(j=0;j<col;j++){
            *(*(mat+i)+j)=0;
            for(k=0;k<col;k++){
                *(*(mat+i)+j)=*(*(mat+i)+j)+*(*(mat1+i)+k)*(*(*(mat2+k)+j));
            }

        }

    }
    printf("The matrix is:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            printf("%d ",*(*(mat+i)+j));
        printf("\n");
    }
    return 0;

}