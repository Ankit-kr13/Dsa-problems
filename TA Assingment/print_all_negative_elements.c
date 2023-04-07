#include<stdio.h>
#include<stdlib.h>
void fill(int *a,int n)
{
    printf("enter %d numbers\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void negative(int *a,int n)
{
    printf("\n");
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            printf("%d  ",a[i]);
        }
    }
    printf("\n");
}
int main()
{
    int n,*a;
    printf("enter the size of the array : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    fill(a,n);
    printf("\nall the negative elements in the array are");
    negative(a,n);
    return 0;
}