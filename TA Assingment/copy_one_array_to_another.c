#include<stdio.h>
#include<stdlib.h>
void fill(int *a, int n)
{
    printf("enter %d numbers\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
}
void copy(int *a,int *b, int n)
{
    for(int i=0;i<n;i++)
    {
        *(b+i)=*(a+i);
    }
}
void display(int *c,int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(c+i));
    }
    printf("\n");
}
int main()
{
    int *a,*b,n;
    printf("enter the size of array : ");;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    b=(int *)malloc(n*sizeof(int));
    fill(a,n);
    copy(a,b,n);
    printf("array a");
    display(a,n);
    printf("array b");
    display(b,n);
    return 0;
}