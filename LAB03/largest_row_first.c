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
void largestrowfirst(int column,int (*a)[column],int row)
{
    int i,j,sum,max=0,largest_row,temp;
    for (int i = 0; i < row; i++)
    {
        sum=0;
        for (int j = 0; j < column; j++)
        {
            sum+=*(*(a+i)+j);
        }
        if(sum>max)
        {
            max=sum;
            largest_row=i;
        }
    }
    for (int i = 0; i < row; i++)
    {
        temp=*(*(a+0)+i);
        *(*(a+0)+i)=*(*(a+largest_row)+i);
        *(*(a+largest_row)+i)=temp;
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
    largestrowfirst(column, a, row);
    printf("\n2d-array after largest row swap\n");
    display(column, a, row);
    return 0;
}