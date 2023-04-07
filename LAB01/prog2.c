// WAP to reverse the contents of an array of n elements.
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of element in an array:\n");
    scanf("%d",&n);
    int arr[10];
    // getting array
    printf("Enter the elements in an array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // reversing
    for(int i=0;i<n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    // printing
    printf("The elements of arrays after reversing:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
return 0;
}