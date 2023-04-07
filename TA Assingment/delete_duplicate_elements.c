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
void delete(int *a,int *n,int position)
{
    int k;
    for(k=position;k<((*n)-1);k++)
    {
        a[k]=a[k+1];
    }
    *n=*n-1;
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
    int n,*a,i,j;
    printf("enter the size of array : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    fill(a,n);
    for(i=0;i<n-1;i++)
    {
        j=i+1;
        while(j<n)
        {
            if(a[i]==a[j])
            {
                delete(a,&n,j);
            }
            else
            j++;
        }
    }
    display(a,n);
    free(a);
    return 0;
}