// WAP to search an element in an array of n numbers.
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
    int key;
    printf("Enter the element to be searched:\n");
    scanf("%d",&key);
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("The element is found at index: %d\n",i);
            flag=1;
        }
    }
    if(flag==0){
        printf("Element not found!!");
    }

return 0;
}