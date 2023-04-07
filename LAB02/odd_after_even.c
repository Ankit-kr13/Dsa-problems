#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,i,n,j=0,temp;
    printf("\nenter size of array : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("\nenter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
        printf("\nenter a number : ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
        j++;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    free(a);
    return 0;
}