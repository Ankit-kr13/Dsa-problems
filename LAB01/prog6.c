// Given an array, WAP to print the next greater element (NGE) for every element. The Next greater
// Element for an element x is the first greater element on the right side of x in array. Elements for
// which no greater element exist, consider next greater element as -1.
// Sample Input & Output
// For the input array [2, 5, 3, 9, 7}, the next greater elements for each element are as follows.
// Element NGE
// 2 5
// 5 9
// 3 9
// 7 -1
#include<stdio.h>
    

int main(){
    int n;
    printf("Enter the number of elements in an array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("-------------------------------------------------------\n");
    printf("ENTER THE ELEMENTS IN AN ARRAY:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("-------------------------------------------------------\n");
    int nge;
    for(int i=0;i<n;i++){
        nge=-1;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                nge=arr[j];
                break;

            }
        }
        printf("%d-->%d\n",arr[i],nge);
    }
return 0;
}