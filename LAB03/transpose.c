#include <stdio.h>
#include<stdlib.h>
void fill(int column, int (*a)[column], int row)
{
    printf("\nenter %d numbers\n",row*column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", (*(a+i)+j));
        }
    }
}
void transpose(int column,int (*a)[column],int row)
{
    int i,j,temp;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (i != j)
            {
                temp = *(*(a+i)+j);
                *(*(a+i)+j) = *(*(a+j)+i);
                *(*(a+j)+i) = temp;
            }
        }
    }

}
void display( int column,int (*a)[column],int row)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        printf("%d  ",*(*(a+i)+j));
        printf("\n");
    }
}
int main()
{
    int row,column, i, j, temp;
    printf("enter number of rows and columns\n");
    scanf("%d %d",&row,&column);
    int (*a)[column];
    a = (int(*)[column])malloc(row * column * sizeof(int));
    fill(column, a, row);
    printf("\noriginal 2d-array\n");
    display(column, a, row);
    transpose(column, a, row);
    printf("\nthe transpose of the matrix is\n");
    display(column, a, row);
    return 0;
}