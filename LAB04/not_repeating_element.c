#include<stdio.h>
#include<stdlib.h>
void data_enter(int *a,int n)
{
    printf("enter %d numbers\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
int not_repeating(int *a,int n)
{
    int r=0,i;
    for(i=0;i<n;i++)
    {
        r=r^a[i];
    }
    return r;
}
void display(int *a,int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int *a,n,data;
    printf("\nenter size of array : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    data_enter(a,n);
    display(a,n);
    printf("\nthe single non repeating element is : %d",not_repeating(a,n));
    free(a);
    return 0;
}