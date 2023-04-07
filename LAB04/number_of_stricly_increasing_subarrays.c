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
int subarrays(int *a,int n)
{
    int count=0,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j-1]<a[j])
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int *a,n,c;
    printf("\nenter size of array : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    data_enter(a,n);
    c=subarrays(a,n);
    printf("\nnumber of striclty increasing subarrays are : %d",c);
    free(a);
    return 0;
}