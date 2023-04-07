#include<stdio.h>
#include<stdlib.h>
void fill(int *a, int size)
{
    printf("enter %d numbers\n",size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",(a + i));
    }
}
void sum(int *a, int size)
{
    int i,sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=*(a + i);
    }
    printf("\nsum of all numbers in the array is : %d",sum);
}
int main()
{
    int *a,size;
    printf("enter size of array : ");
    scanf("%d", &size);
    a=(int *)malloc(size*sizeof(int));
    fill(a,size);
    sum(a,size);
    return 0;
}