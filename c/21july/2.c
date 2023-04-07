// WAP to reverse the contents of an array of n elements.

#include<stdio.h>

int main(){

    int arr[50];

     int n;
    printf("Enter the no of elements ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<n;i++){

       printf("%d \n",arr[i]);
       
    }
    printf("array in reverse order:");

    for(int i = n-1; i >= 0;i--){

         printf("%d ",arr[i]);

    }
}