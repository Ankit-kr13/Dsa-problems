#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row,column,i,j,size,c=0,*b;
    printf("enter number of rows and columns\n");
    scanf("%d %d",&row,&column);
    size=row*column;
    int (*a)[column];
    b=(int *)malloc(size*sizeof(int));
    a=(int (*)[column])malloc(size*sizeof(int));
    printf("\nenter %d numbers\n",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",(b+i));
    }
    printf("\n1-D array is\n");
    for(i=0;i<size;i++)
    {
        printf("%d  ",*(b+i));
    }
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            *(*(a+j)+i)=*(b+c);
            c++;
        }
    }
    printf("\n2-D array in column major is\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d\t",*(*(a+i)+j));
        }
        printf("\n");
    }
    free(a);
    free(b);
    return 0;
}