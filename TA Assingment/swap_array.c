#include<stdio.h>
#include<stdlib.h>
void fill(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
}
void swap(int *a,int *b, int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        temp=*(b+i);
        *(b+i)=*(a+i);
        *(a+i)=temp;
    }
}
void display(int *c,int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(c+i));
    }
    printf("\n\n");
}
int main()
{
    int *a,*b,n;
    printf("enter the size of array : ");;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    b=(int *)malloc(n*sizeof(int));
    printf("enter %d numbers in array a\n",n);
    fill(a,n);
    printf("enter %d numbers in array b\n",n);
    fill(b,n);
    printf("array a before swap");
    display(a,n);
    printf("array b before swap");
    display(b,n);
    swap(a,b,n);
    printf("array a after swap");
    display(a,n);
    printf("array b after swap");
    display(b,n);
    return 0;
}