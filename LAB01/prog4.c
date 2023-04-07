//WAP to sort an array of n numbers.
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of element in an array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element %d :\n",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("The elements of arrays:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
return 0;
}