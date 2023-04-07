// WAP to find out the smallest and largest element stored in an array of n integers.
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of element in an array:\n");
    scanf("%d",&n);
    int arr[10];
    for(int i=0;i<n;i++){
        printf("Enter the element %d :\n",i+1);
        scanf("%d",&arr[i]);
    }
    int max,min;
    max=min=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    printf("The smallest element stored in array: %d\n",min);
    printf("The largest element stored in array: %d\n",max);

return 0;
}