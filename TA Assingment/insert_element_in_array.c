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
void insert(int *a,int *n)
{
    int i,num,position;
    printf("\nenter the position where you want to enter the number : ");
    scanf("%d",&position);
    for(i=*n;i>position;i--)
    {
        a[i]=a[i-1];
    }
    printf("\nenter the number you want to enter at position %d : ",position);
    scanf("%d",&num);
    a[position]=num;
    *n+=1;
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
    int n,*a;
    printf("enter the number of element you want to enter in the array : ");
    scanf("%d",&n);
    a=(int *)malloc(100*sizeof(int));
    fill(a,n);
    insert(a,&n);
    display(a,n);
    return 0;
}