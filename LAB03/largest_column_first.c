#include<stdio.h>
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
void largestcolumnfirst(int column,int (*a)[column],int row)
{
    int i,j,sum,max=0,largest_column,temp;
    for (int i = 0; i < column; i++)
    {
        sum=0;
        for (int j = 0; j <row; j++)
        {
            sum+=*(*(a+j)+i);
        }
        if(sum>max)
        {
            max=sum;
            largest_column=i;
        }
    }
    for (int i = 0; i < row; i++)
    {
        temp=*(*(a+j)+i);
        *(*(a+j)+i)=*(*(a+i)+largest_column);
        *(*(a+i)+largest_column)=temp;
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
    int row,column;
    printf("enter number of rows and columns\n");
    scanf("%d %d",&row,&column);
    int (*a)[column];
    a = (int(*)[column])malloc(row * column * sizeof(int));
    fill(column, a, row);
    printf("\noriginal 2d-array\n");
    display(column, a, row);
    largestcolumnfirst(column, a, row);
    printf("\n2d-array after largest column swap\n");
    display(column, a, row);
    return 0;
}