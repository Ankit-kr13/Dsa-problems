#include<stdio.h>
#include <stdlib.h>
void fill(int column, int (*a)[column], int row)
{
    printf("\nenter %d numbers\n",row*column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void row_column_zero(int column, int (*a)[column], int row)
{
    int i,j,k,(*b)[column];
    b = (int(*)[column])malloc(row * column * sizeof(int));
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            b[i][j]=-1;
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(a[i][j]==0)
            {
                for(k=0;k<row;k++)
                    b[k][j]=0;
                for(k=0;k<column;k++)
                    b[i][k]=0;
            }
            else if((a[i][j]==1)&&b[i][j]==-1)
            b[i][j]=a[i][j];
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            a[i][j]=b[i][j];
        }
    }
    free(b);
}
void display( int column,int (*d)[column],int row)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        printf("%d\t",d[i][j]);
        printf("\n");
    }
}
int main()
{
     int row, column;
    printf("\nenter number of rows and columns\n");
    scanf("%d %d", &row, &column);
    int(*a)[column];
    a = (int(*)[column])malloc(row * column * sizeof(int));
    fill(column, a, row);
    printf("\noriginal array\n");
    display(column, a, row);
    row_column_zero(column, a, row);
    printf("\nnew array\n");
    display(column, a, row);
    free(a);
    return 0;
}