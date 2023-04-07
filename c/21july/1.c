// WAP to find out the smallest and largest element stored in an array of n integers.

#include<stdio.h>

int main(){

    int arr[100];

    int n;
    printf("Enter the no of elements ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int small = arr[0];
    int large = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
        }
        
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }

    printf("\nLargest element is : %d", large);
    printf("\nSmallest element is : %d", small);

    return 0;
}


